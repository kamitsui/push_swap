#! /bin/bash
PUSH_SWAP=./a.out

printf -- "-------------------\n"
VAR="-2147483648 -2147483647 2147483647 0"

printf "$PUSH_SWAP $VAR\n"
$PUSH_SWAP $VAR
