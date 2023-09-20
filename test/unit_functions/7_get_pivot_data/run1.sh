#! /bin/bash
PUSH_SWAP=./a.out
CHECKER=../../../checker
#CHECKER=../../../checker_Mac

printf -- "-------------------\n"
# OK
VAR="42 55 54 53 52 51 9 8 7 6 5 4 3 2 1"

printf "$PUSH_SWAP $VAR\n"
$PUSH_SWAP $VAR
#printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
#$PUSH_SWAP $VAR | $CHECKER $VAR
