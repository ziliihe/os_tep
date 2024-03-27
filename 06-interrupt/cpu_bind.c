#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    cpu_set_t cpu_set;
    CPU_ZERO(&cpu_set); // 清空 CPU 亲和性掩码
    CPU_SET(0, &cpu_set); // 将第 0 号 CPU 加入掩码

    pid_t tid = syscall(SYS_gettid); // 获取当前线程 ID

    if (sched_setaffinity(tid, sizeof(cpu_set_t), &cpu_set) == -1) {
        perror("sched_setaffinity");
        return 1;
    }

    printf("Thread %d has been bound to CPU 0.\n", tid);

    // 在这里写你的线程代码

    return 0;
}
