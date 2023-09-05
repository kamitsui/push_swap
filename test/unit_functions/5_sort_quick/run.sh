#! /bin/bash
PUSH_SWAP=./push_swap

printf -- "---- test code ----\n"
cat srcs/test_sort_quick.c

printf -- "-------------------\n"
VAR="42 3 2 0 100 59 300 43"
printf "$PUSH_SWAP $VAR\n"
$PUSH_SWAP $VAR
