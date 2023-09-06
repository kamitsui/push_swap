# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:58:25 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/06 14:53:17 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target Directory
DIR1 = 1_is_sorted
DIR2 = 2_count_elements
DIR3 = 3_ft_isint
DIR4 = 4_partition
DIR5 = 5_manual_sort_using_partition
DIR6 = 6_sort_quick

# Target name
NAME1 = $(DIR1)/push_swap
NAME2 = $(DIR2)/a.out
NAME3 = $(DIR3)/a.out
NAME4 = $(DIR4)/a.out
NAME5 = $(DIR5)/push_swap
NAME6 = $(DIR6)/push_swap

# Run Target
RUN1 = cd $(DIR1) ; ./run.sh ; echo "\n\n"
RUN2 = cd $(DIR2) ; make run ; echo "\n\n"
RUN3 = cd $(DIR3) ; ./run.sh ; echo "\n\n"
RUN4 = cd $(DIR4) ; ./run.sh ; echo "\n\n"
RUN5 = cd $(DIR5) ; ./run.sh ; echo "\n\n"
RUN6 = cd $(DIR6) ; ./run.sh ; echo "\n\n"

# Default target
all : $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5) $(NAME6)

# First Target
1 :
	make -C $(DIR1)
$(NAME1) :
	make -C $(DIR1)

# Second Target
2 :
	make -C $(DIR2)
$(NAME2) :
	make -C $(DIR2)

# Third Target
3 :
	make -C $(DIR3)
$(NAME3) :
	make -C $(DIR3)

# Forth Target
4 :
	make -C $(DIR4)
$(NAME4) :
	make -C $(DIR4)

# Fifth Target
5 :
	make -C $(DIR5)
$(NAME5) :
	make -C $(DIR5)

# Sixth Target
6 :
	make -C $(DIR6)
$(NAME6) :
	make -C $(DIR6)

# Run Target
run :
	$(RUN1)
	$(RUN2)
	$(RUN3)
	$(RUN4)
	$(RUN5)
	$(RUN6)

# Run choose Target
run1 :
	$(RUN1)
run2 :
	$(RUN2)
run3 :
	$(RUN3)
run4 :
	$(RUN4)
run5 :
	$(RUN5)
run6 :
	$(RUN6)

# Clean target
clean:
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5) $(NAME6)

# Clean and remove target
fclean: clean

# Rebuild target
re: fclean all

.PHONY: all 1 2 3 4 5 6 fclean clean re run run1 run2 run3 run4 run5 run6
