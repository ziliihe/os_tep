#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>


// int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask);
static inline uint64_t rdtsc() {
    uint64_t tsc;
    asm volatile("rdtsc":"=A"(tsc));

    return tsc;
}

int main()
{
    struct timeval tv1;
    struct timezone tz1;

    int status = gettimeofday(&tv1, &tz1);
    printf("seconds: %ld.%ld status: %d\n", tv1.tv_sec, tv1.tv_usec, status);
    printf("miniutes: %d, DST: %d\n", tz1.tz_minuteswest, tz1.tz_dsttime);


    uint64_t start, end;
    double elapsed_cycles;

    start = rdtsc();
    printf("hello world\n");
    end = rdtsc();
    elapsed_cycles = (double)(end - start);

    printf("Elapsed cycles: %.0f\n", elapsed_cycles);

    return 0;
}
