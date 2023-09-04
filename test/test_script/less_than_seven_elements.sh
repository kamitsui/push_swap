#! /bin/bash
PUSH_SWAP=../../push_swap
CHECKER=../../checker


printf -- "\n---- Two elements Test ----\n\n"

# Case : 2 1
array="2 1"
printf "Case : $array\n"
printf "$PUSH_SWAP $array | $CHECKER $array\n"
$PUSH_SWAP $array | $CHECKER $array

# Case : 1 2
array="1 2"
printf "Case : $array\n"
printf "$PUSH_SWAP $array | $CHECKER $array\n"
$PUSH_SWAP $array | $CHECKER $array

printf -- "\n---- Three elements Test ----\n\n"

# Case : 3 2 1
array="3 2 1"
printf "Case : $array\n"
printf "$PUSH_SWAP $array | $CHECKER $array\n"
$PUSH_SWAP $array | $CHECKER $array

# Case : 1 3 2
array="1 3 2"
printf "Case : $array\n"
printf "$PUSH_SWAP $array | $CHECKER $array\n"
$PUSH_SWAP $array | $CHECKER $array

# Case : 2 3 1
array="2 3 1"
printf "Case : $array\n"
printf "$PUSH_SWAP $array | $CHECKER $array\n"
$PUSH_SWAP $array | $CHECKER $array

# Case : 2 1 3
array="2 1 3"
printf "Case : $array\n"
printf "$PUSH_SWAP $array | $CHECKER $array\n"
$PUSH_SWAP $array | $CHECKER $array

# Case : 3 1 2
array="3 1 2"
printf "Case : $array\n"
printf "$PUSH_SWAP $array | $CHECKER $array\n"
$PUSH_SWAP $array | $CHECKER $array
