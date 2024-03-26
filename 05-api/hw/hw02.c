#include <stdio.h>
#include <fcntl.h> // open
#include <stdlib.h> // exit
#include <unistd.h> // fork 
#include <string.h> // strlen
#include <sys/stat.h> // S_IRWXU

int main() {
    int fd = open("out/hw02.out", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd < 0) {
        fprintf(stderr, "open failed!");
        exit(1);
    }

    int rc = fork();
    char *mdata = "MainProc -> Zhanghui\n";
    char *cdata = "SubProc  -> Hezili\n";
    if (rc < 0) {
        fprintf(stderr, "fork failed!");
        exit(1);
    } else if (rc == 0) {
        ssize_t bytes_written = write(fd, cdata, strlen(cdata));
        if (bytes_written == -1) {
            fprintf(stderr, "main write failed");
            exit(1);
        }
    } else {
        // 主进程写入
        ssize_t bytes_written = write(fd, mdata, strlen(mdata));
        if (bytes_written == -1) {
            fprintf(stderr, "main write failed");
            exit(1);
        }
    }

    if (close(fd) == -1) {
        fprintf(stderr, "close failed");
        exit(1);
    }

    return 0;
}
