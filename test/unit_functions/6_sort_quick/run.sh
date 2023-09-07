#! /bin/bash
PUSH_SWAP=./push_swap
CHECKER=../../../checker

printf -- "-------------------\n"
VAR="42 2 1 3 100 10 32 23 6 59 300 43"
printf "$PUSH_SWAP $VAR\n"
$PUSH_SWAP $VAR
printf -- "-------------------\n"
printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
$PUSH_SWAP $VAR | $CHECKER $VAR
