#! /bin/bash
PUSH_SWAP=./push_swap
CHECKER=../../../checker
#CHECKER=../../../checker_Mac

printf -- "------------------- sorted top & bottom side\n"
VAR="42 51 52 53 54 55 1 2 3 4 5 6 7 8 9"

printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
$PUSH_SWAP $VAR | $CHECKER $VAR
