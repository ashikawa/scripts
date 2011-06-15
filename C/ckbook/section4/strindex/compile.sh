#!/bin/sh

gcc -c main.c
gcc -c getline.c

gcc main.o getline.o -o main

