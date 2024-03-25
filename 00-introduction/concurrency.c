#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

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
    pthread_t p1, p2;
    printf("Initial Value: %d\n", counter);

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);

    printf("Final Value: %d\n", counter);

    return 0;
}