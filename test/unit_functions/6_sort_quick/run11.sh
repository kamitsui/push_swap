#! /bin/bash
PUSH_SWAP=./push_swap
CHECKER=../../../checker
#CHECKER=../../../checker_Mac

printf -- "------------------- sorted top & bottom side\n"
VAR="42 11 51 20 52 13 23 14 53 24 54 55 1 2 3 25 16 4 5 6 26 7 28 8 9 60 66 22 21 62 69 67 61"

printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
$PUSH_SWAP $VAR | $CHECKER $VAR
