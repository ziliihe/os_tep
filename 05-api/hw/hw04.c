#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void run1() {
    printf("FUNCTION: run1\n");
    int error = execl("/bin/ls", "ls", "-l", NULL);
    if (error == -1) {
        perror("execl");
        return;
    }
}

void run2() {
    printf("FUNCTION: run2\n");
    char *envp[] = {"PATH=/bin", NULL}; // 环境变量
    int error = execle("/bin/ls", "ls", "-l", NULL, envp);
    if (error == -1) {
        perror("execle");
        return;
    }
}

void run3() {
    printf("FUNCTION: run3\n");
    int error = execlp("ls", "ls", "-ltr", NULL);  // 不需要完整路径，从PATH中搜索
    if (error == -1) {
        perror("execlp");
        return;
    }
}

void run4() {
    printf("FUNCTION: run4\n");
    char *args[] = {"ls", "-tl", NULL};  // 参数数组
    int error = execv("/bin/ls", args);  // 需要完整路径
    if (error == -1) {
        perror("execv");
        return;
    }
}

void run5() {
    printf("FUNCTION: run5\n");
    char *args[] = {"ls", "-tl", NULL};  // 参数数组
    int error = execvp("ls", args);  // 不需要完整路径，从PATH中搜索
    if (error == -1) {
        perror("execvp");
        return;
    }
}

int main(int argc, char *argv[])
{
    printf("\nCurrent Process PID: [MAIN] %d\n", getpid());
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <1,2...,4>\n", argv[0]);
        exit(1);
    }
    int type = atoi(argv[1]);
    switch (type)
    {
    case 1:
        run1();
        break;
    case 2:
        run2();
        break;
    case 3:
        run3();
        break;
    case 4:
        run4();
        break;
    case 5:
        run5();
        break;
    default:
        break;
    }
    
    return 0;
}