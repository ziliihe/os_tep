#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> // exit

int main(int argc, char *argv[])
{
    printf("Current Process PID: [MAIN] %d\n", (int)getpid());
    int main_x = 100;
    printf("Before Fork, main_x = %d\n", main_x);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if ( rc == 0 ) {
        printf("Child Process PID  : [CHILD] %d\n", (int)getpid());
        printf("Child Process, main_x = %d\n", main_x); // access
        main_x += 899; // modify
    } else {
        printf("Main, Before Wait, main_x = %d\n", main_x);
        int wc = wait(NULL);
        printf("MAIN Process PID   : [MAIN] %d, Wait Result: %d\n", (int)getpid(), wc);
        printf("Main, After  Wait, main_x = %d\n", main_x);
        main_x += 1; // main process modify
    }
    // 这里是子进程和父进程都会执行到的结果
    // 子进程 main_x = 999
    // 父进程 main_x = 101
    // 子进程会复制父进程的数据
    // 可以看出父进程和子进程的数据是隔离的
    printf("Finally main_x --> %d\n", main_x);

    return 0;
}
