#!/bin/bash

gcc -o create create.c;
if [[ "$?" != "0" ]]; then
    return 1
fi;

gcc -o read read.c;
if [[ "$?" != "0" ]]; then
    return 1
fi;

gcc -o write write.c;
if [[ "$?" != "0" ]]; then
    return 1
fi;