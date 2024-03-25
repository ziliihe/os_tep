#ifndef XV6_CONTEXT_SWITCH_H
#define XV6_CONTEXT_SWITCH_H

#include <stdlib.h>

#define NOFILE 1024

/*
 *
 * xv6 存储和恢复的寄存器
 * 为了停止和后续重新运行程序设计
 *
 */
struct context
{
    int eip;
    int esp;
    int ebx;
    int ecx;
    int edx;
    int esi;
    int edi;
    int ebp;
};

/*
 *
 * 程序可能出现的状态
 *
 */
enum proc_state {
    UNUSED,
    EMBRYO,
    SLEEPING,
    RUNNABLE,
    RUNNING,
    ZOMBIE
};

/*
 *
 * xv6 追踪每个进程的信息
 * 包括寄存器上下文和状态
 *
 */
struct proc {
    char *mem;                // 进程初始内存
    size_t sz;                // 进程内存大小
    char *kstack;             // 内核栈底层结构

    enum proc_state state;    // 进程状态
    int pid;                  // 进程ID
    struct proc *parent;      // 父进程
    void *chan;               // 如果非 0， sleep on chan
    int killed;              // 如果非 0， 进程已经终止
    struct file *ofile[NOFILE]; // 打开的文件列表
    struct inode *cwd;          // 当前工作目录
    struct context context;     // 切换到此，以运行进程
    struct trapframe *tf;        // 当前中断的陷阱帧
};
#endif