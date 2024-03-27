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

ECHO "homework 01"
gcc -o out/hw01 hw01.c -Wall
out/hw01

ECHO "homework 02"
gcc -o out/hw02 hw02.c -Wall
out/hw02
cat out/hw02.out

ECHO "homework 03"
gcc -o out/hw03 hw03.c -Wall
out/hw03

ECHO "homework 03 pipe"
target=hw03_pipe
gcc -o out/${target} ${target}.c -Wall
out/${target}

ECHO "homework 04"
target=hw04
gcc -o out/${target} ${target}.c -Wall
out/${target} 1
out/${target} 2
out/${target} 3
out/${target} 4
out/${target} 5

ECHO "homework 05"
target=hw05
gcc -o out/${target} ${target}.c -Wall
out/${target}

ECHO "homework 06"
target=hw06
gcc -o out/${target} ${target}.c -Wall
out/${target}

ECHO "homework 07"
target=hw07
gcc -o out/${target} ${target}.c -Wall
out/${target}

ECHO "homework 08"
target=hw08
gcc -o out/${target} ${target}.c -Wall
out/${target}