#!/bin/bash
set -e

PURPLE='\033[1;35m'
RESET='\033[0m'

function ECHO() {
    content=$1
    echo
    echo -e "****************** ${PURPLE}${content}${RESET} ******************"
}


ECHO "threads"
gcc -o out/concurrency concurrency.c -Wall -pthread
out/concurrency 10000
out/concurrency 10000
out/concurrency 10000
out/concurrency 10000

ECHO 'write to file'
rm -f /tmp/file
gcc -o out/file file.c -Wall
out/file
cat /tmp/file
