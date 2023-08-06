# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    simple.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 16:28:24 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/06 21:49:40 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! bin/bash

# Non Duplicates
#./push_swap 1 3 4 5 6 7 42 30 2 20

# Exist Duplicates
# ./push_swap 1 3 4 4 6 7 42 30 2 20
#                 ^ ^

# Subject example 1
./push_swap 2 1 3 6 5 8

# Subject example 2
# ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Subject example 3
# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
