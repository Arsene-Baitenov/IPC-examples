#!/bin/bash

gcc -o shm -lrt shm.c;
if [[ "$?" != "0" ]]; then
    return 1;
fi;