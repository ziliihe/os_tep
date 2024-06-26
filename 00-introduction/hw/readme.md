1. `./process-run.py -l 5:100,5:100`

cpu 使用率，100%；`-l` 参数指定模拟进程运行情况，用`,`分隔进程，每个进程用`:`分隔，前面是一个进程要执行的指令条数和后面是占用 cpu 的概率。

2. `./process-run.py -l 4:100,1:0`

不太明白的是为什么 `I/O` 进程一条指令阻塞了 5 个类 CPU 时钟周期呢？

是否发起 `I/O` 和结束 `I/O` 也要算作一条指令，也需要占用相应的时钟周期呢？

3. `./process-run.py -l 1:0,4:100`

从这里的执行结果看，确实 `I/O` 在这个实验的设计中，开始和结束 `I/O` 需要占用一个时钟周期。

但是这里 `I/O` 先执行然后阻塞，CPU 进程指令可以继续执行，所以这里基本耗时 5 个 CPU 时钟周期，即 2 中耗时的一半左右。

4. `./process-run.py -l 1:0,4:100 -c -S SWITCH_ON_END`

由于这里的标志 `SWITCH_ON_END` 决定了发起 `I/O` 时，系统不会切换到另一个进程，而是等待进程完成，所以即使是先发起 `I/O`，但是不会执行其他 CPU 进程，而是等待 `I/O` 完成，耗时和 2 中一样。

5. `./process-run.py -l 1:0,4:100 -c -S SWITCH_ON_IO`

在发起 `I/O` 时，系统主动切换其他 CPU 进程运行，提高 CPU 的利用率。

6. `./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p`

`I/O` 和 CPU 进程可能交替执行，而不是先连续执行多个 `I/O` 阻塞。

7. `./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE -c -p`

`I/O` 保证连续执行，期间可以正常执行 CPU 进程，提升 CPU 的利用率，一般能到 100%

8. 确保发起 `I/O` 阻塞期间能够正常执行 CPU 进程能够提升 CPU 利用率，提升系统效率。

