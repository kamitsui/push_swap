#! /bin/bash
A_OUT=./a.out

printf -- "---- test code ----\n"
cat srcs/test_partition.c

printf -- "-------------------\n"
$A_OUT
