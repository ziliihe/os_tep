#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int rc = fork();
    if (rc < 0) {
        perror("fork failed");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
    } else {
        sleep(0.1); // 等待子进程输出
        printf("goodbye\n"); // 父进程输出
    }

    return 0;
}