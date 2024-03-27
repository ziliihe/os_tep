#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    printf("Parent Process         PID: %d\n", (int)getpid());

    int rc = fork();
    if (rc < 0) {
        perror("fork");
        exit(1);
    } else if (rc == 0) {
        printf("This is Child Process  PID: %d\n", (int)getpid());
        int wc = wait(NULL); // -1 子进程并没有子进程，所以wait()函数无法等待任何子进程的退出状态
        printf("Child Process Wait Return : %d, ERRNO: %d -> [%s]\n", wc, errno, strerror(errno));
    } else {
        int wc = wait(NULL); // 返回子进程 PID
        printf("This is Parent Process PID: %d, Wait Return -> %d\n", (int)getpid(), wc);
    }

    return 0;
}  