#! /bin/bash
PUSH_SWAP=./a.out
CHECKER=../../../checker
#CHECKER=../../../checker_Mac

printf -- "-------------------\n"
# OK
VAR="42 55 54 53 52 51 9 8 -47 -46 -45 -44 -43 -42 -41 -40"

printf "$PUSH_SWAP $VAR\n"
$PUSH_SWAP $VAR
#printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
#$PUSH_SWAP $VAR | $CHECKER $VAR
