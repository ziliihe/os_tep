#include <stdio.h>
#include <stdlib.h>

volatile int counter = 0;
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        counter++;
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: threads <value> \n");
        exit(1);
    }

    loops = atoi(argv[1]);
}