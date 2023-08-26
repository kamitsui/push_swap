#! /bin/bash
PUSH_SWAP=./push_swap

# Not sort
DATA="2 1 3 6 5 8"
printf "./push_swap $DATA\n"
$PUSH_SWAP $DATA
DATA=" 5 4 3 2 1"
printf "./push_swap $DATA\n"
$PUSH_SWAP $DATA

# Sorted
DATA=" 1 2 3 5 6 8"
printf "./push_swap $DATA\n"
$PUSH_SWAP $DATA
