#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Parent Process PID: %d\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        perror("fork failed");
        exit(1);
    } else if (rc == 0) {
        printf("This is the child process, PID: %d\n", (int)getpid());
    } else {
        printf("In Parent Process, rc = %d\n", rc);  
        // wait() 函数会等待任何一个子进程结束，并返回第一个结束的子进程的状态。
        // waitpid() 函数可以指定等待特定的子进程，或者根据不同的选项来等待不同条件下的子进程，
        // 例如等待任何子进程、等待一个特定进程、等待一个特定进程组的任何成员、等待任何子进程组、或者等待某个特定的子进程并且不阻塞父进程。
        // wait() 函数无法指定等待的子进程，所以如果没有子进程退出时调用，它会阻塞父进程，除非设置了WNOHANG选项。
        // waitpid() 函数更加灵活，可以选择是否阻塞父进程，以及等待的子进程的具体情况。
        int wcp = waitpid(rc, NULL, 0);  // 0 阻塞，WNOHANG 不阻塞父进程， WUNTRACED 返回状态
        printf("[waitpid] Child Process %d terminated\n", wcp);
    }
    return 0;
}