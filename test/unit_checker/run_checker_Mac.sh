#! /bin/bash
PUSH_SWAP=../../push_swap
CHECKER=../../checker_Mac

# file include integer array
filename="file.txt"
#file.txt is this strings "1 3 4 5 6 7 42 30 2 20"

printf -- "---- Variable  Test ----\n"

# Read & Set data to variable
read -r array_from_file < "$filename"
printf "read -r array_from_file < \"\$filename\"\n"
printf "\$PUSH_SWAP \$array_from_file | $CHECKER \$array_from_file\n"

# test checker
$PUSH_SWAP $array_from_file | $CHECKER $array_from_file
