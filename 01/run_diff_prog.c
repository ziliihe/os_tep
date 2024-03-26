#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("Hello World ([MAIN]PID: %d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello, I am child ([CHILD] PID: %d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("wc"); // program: "wc" (word count)
        myargs[1] = strdup("./run_diff_prog.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("This shouldn't print out");
    } else {
        int wc = wait(NULL);
        printf("Hello, I am parent of %d (wc: %d) ([PARENT] PID: %d)\n", rc, wc, (int)getpid());
    }

    return 0;
}