#!/bin/bash
set -e

PURPLE='\033[1;35m'
RESET='\033[0m'

if [ ! -d out ];then
    mkdir out
fi

function ECHO() {
    content=$1
    echo
    echo -e "****************** ${PURPLE}${content}${RESET} ******************"
}

ECHO "create process"
gcc -o out/create_proc create_proc.c -Wall
out/create_proc

ECHO "wait sub-process finished"
gcc -o out/wait_sub_proc wait_sub_proc.c -Wall
out/wait_sub_proc

ECHO "run different program"
gcc -o out/run_diff_prog run_diff_prog.c -Wall
out/run_diff_prog