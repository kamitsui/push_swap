#! /bin/bash
PUSH_SWAP=../../push_swap

printf -- "---- Err  Test (has Duplicate) ----\n"

# Exist Duplicates
DUP_DATA="1 3 4 4 6 7 42 30 2 20"
#             ^ ^
printf "$PUSH_SWAP $DUP_DATA\n"
$PUSH_SWAP $DUP_DATA
