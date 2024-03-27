#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Parent Process PID: %d\n", (int)getpid());
    int rc = fork();

    if (rc < 0) {
        perror("fork failed");
        exit(1);
    } else if (rc == 0) {
        printf("This is the child process, PID: %d\n", (int)getpid());
        close(STDOUT_FILENO);
        printf("After close STDOUT_FILENO\n"); // 后续不会打印到终端标准输出显示
    } else {
        int wcp = waitpid(rc, NULL, 0);
        printf("This is the parent process PID: %d, wait child PID: %d\n", (int)getpid(), wcp);
    }
    return 0;
}