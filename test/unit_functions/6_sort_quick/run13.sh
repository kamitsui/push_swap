#! /bin/bash
PUSH_SWAP=./push_swap
CHECKER=../../../checker
#CHECKER=../../../checker_Mac

printf -- "------------------- sorted top & bottom side\n"
VAR="18 14 -17 -19 -8 31 10 34 41 5 -24 24 32 -27 2 -1 42 -34 -2 33 45 39 46 21 13 -48 -20 37 22 -28 49 6 -50 17 -49 -3 -36 -16 27 19 -6 -9 -18 20 3 -37 -31 29 11 -12 9 4 -14 -22 -46 0 -11 -44 -33 -10 44 -39 -30 -7 30 40 16 -23 47 -35 -40 38 -47 25 -5 -29 8 1 -4 -13 28 -38 -45 26 -43 35 -26 43 -25 -42 -15 23 36 12 -21 7 15 48 -41 -32"

printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
$PUSH_SWAP $VAR | $CHECKER $VAR
