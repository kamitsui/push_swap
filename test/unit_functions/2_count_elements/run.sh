#! /bin/bash
A_OUT=./a.out

VAR1="1 2 3 4 5 6"
VAR2="7 8 9 10"
VAR3="11"
VAR4="12"
VAR5="13"
VAR6="14 15"

printf "$A_OUT $VAR1 $VAR2 $VAR3 $VAR4 $VAR5 $VAR6\n"
$A_OUT $VAR1 $VAR2 $VAR3 $VAR4 $VAR5 $VAR6
