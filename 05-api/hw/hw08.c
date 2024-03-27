#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pfd[2];
    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(1);
    }

    int rc1 = fork();
    if (rc1 < 0) {
        perror("fork1");
        exit(1);
    } else if (rc1 == 0) {
        // 子进程 1 标准输出
        // 关闭读端
        close(pfd[0]);
        dup2(pfd[1], STDOUT_FILENO);
        printf("Hello from child 1\n");
        close(pfd[1]);
        exit(EXIT_SUCCESS);
    } else {
        int rc2 = fork();
        if (rc2 < 0) {
            perror("fork2");
            exit(1);
        } else if (rc2 == 0) {
            // 子进程 2 标准输入连接子进程 1标准输出
            close(pfd[1]);
            dup2(pfd[0], STDIN_FILENO);
            close(pfd[0]);
            execlp("wc", "wc", "-l", NULL);
        } else {
            close(pfd[0]);
            close(pfd[1]);
            waitpid(rc1, NULL, 0);
            waitpid(rc2, NULL, 0);
            printf("Parent Process PID:%d\n", (int)getpid());
        }
    }
   
    return 0;
}