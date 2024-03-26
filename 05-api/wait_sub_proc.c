#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main(int argc, char *argv[])
{
    printf("Hello World (PID: %d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) { // 创建子进程失败
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // 子进程
        printf("Hello, I am child (PID: %d)\n", (int) getpid());
    } else {
        int wc = wait(NULL);
        printf("Hello, I am parent of %d (wc: %d)(PID: %d)\n",
            rc, wc, (int) getpid());
    }

    return 0;
}