#! /bin/bash
#PUSH_SWAP=../../push_swap
CHECKER=../../checker

# file include integer array
filename="file.txt"
#file.txt is this strings "1 3 4 5 6 7 42 30 2 20"

printf -- "---- Variable  Test ----\n"

# Read & Set data to variable
read -r array_from_file < "$filename"
printf "read -r array_from_file < \"\$filename\"\n"
printf "$CHECKER \$array_from_file\n"

# test checker
$CHECKER $array_from_file

# Subject example 2
# ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Subject example 3
# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
