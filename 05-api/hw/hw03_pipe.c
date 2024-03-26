#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    int rc = fork();
    if (rc < 0) {
        perror("fork");
        exit(1);
    } else if(rc == 0) {
        close(pipefd[0]); // 关闭读取端
        printf("hello\n");
        write(pipefd[1], "x", 1); // 数据写入管道
        close(pipefd[1]); // 关闭写入端
    } else {
        close(pipefd[1]); // 关闭写入端
        char buffer; // 从管道读取数据，阻塞直到子进程写入数据

        read(pipefd[0], &buffer, 1);
        printf("goodbye\n");
        close(pipefd[0]);
    }

    return 0;
}