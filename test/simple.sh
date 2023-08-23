#! /bin/bash
PUSH_SWAP=../push_swap
CHECKER=../checker_Mac

# simple array
filename="file.txt"


# Non Duplicates
#./push_swap 1 3 4 5 6 7 42 30 2 20

# Exist Duplicates
# ./push_swap 1 3 4 4 6 7 42 30 2 20
#                 ^ ^

# Subject example 1
read -r array_from_file < "$filename"
$PUSH_SWAP $array_from_file

# Subject example 2
# ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Subject example 3
# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
