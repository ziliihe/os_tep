#!/bin/bash
set -e

if [ ! -d out ];then
    mkdir out
fi

gcc -o out/hw hw.c -Wall
out/hw

gcc -o out/cpu_bind cpu_bind.c -Wall -pthread
out/cpu_bind
