#! /bin/bash
PUSH_SWAP=./push_swap
CHECKER=../../../checker
#CHECKER=../../../checker_Mac

printf -- "------------------- sorted top & bottom side\n"
VAR="1322353406 1911996404 -481577768 -1644101532 1619028276 483400796 -325703432 -1677793369 -1031401796 -400247698"

printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
$PUSH_SWAP $VAR | $CHECKER $VAR
