#! /bin/bash
PUSH_SWAP=./push_swap

#printf -- "---- test code ----\n"
#cat srcs/test_partition.c

printf -- "-------------------\n"
VAR="42 2 1 3 100 10 32 23 6 59 300 43"
printf "$PUSH_SWAP $VAR\n"
$PUSH_SWAP $VAR
