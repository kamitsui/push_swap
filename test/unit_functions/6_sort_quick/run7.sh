#! /bin/bash
PUSH_SWAP=./push_swap
CHECKER=../../../checker
#CHECKER=../../../checker_Mac

printf -- "-------------------\n"
VAR="49 42 32 86 60 30 6 23 57 8 55 50 61 79 90 44 47 85 33 89 83 3 38 13 45 41 2 9 25 94 22 39 46 87 74 11 35 59 100 54 20 29 4 1 93 7 68 48 28 84 69 62 77 52 17 75 82 36 76 24 31 34 5 40 78 72 65 16 99 81 18 95 14 27 97 43 88 70 56 71 10 21 26 19 92 58 73 80 96 51 63 66 67 15 37 12 91 64 53 98"

printf "$PUSH_SWAP $VAR | $CHECKER $VAR\n"
$PUSH_SWAP $VAR | $CHECKER $VAR
