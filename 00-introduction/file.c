#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> /* S_IRWXU 所有者有rwx*/

int main(int argc, char *argv[]) {
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

    assert(fd > -1);
    int rc = write(fd, "Hello, World!\n",14);
    assert(rc == 14);
    close(fd);

    return 0;
}