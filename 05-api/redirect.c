#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //close(STDOUT_FILENO);
        int fd = open("./out/redirect.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        if (fd < 0) {
            fprintf(stderr, "open failed\n");
            exit(1);
        }

        if (dup2(fd, STDOUT_FILENO) == -1) {
            fprintf(stderr, "dup2 failed\n");
            exit(1);
        }
        close(fd);

        printf("output by printf function: \n");
        fflush(stdout);

        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("./redirect.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    } else {
        int wc = wait(NULL);
        printf("MAIN: WAIT: FINISHED -> %d\n", wc);
    }
    return 0;
}
