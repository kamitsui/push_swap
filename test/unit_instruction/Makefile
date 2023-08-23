# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:58:25 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/22 21:46:28 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target Directory
DIR1 = 1_example_of_subject
DIR2 = 2_ss
#DIR3 = 3_parse
#DIR4 = 4_parse_exec
#DIR5 = 5_parse_traverse_exec

# Target name
NAME1 = $(DIR1)/push_swap
NAME2 = $(DIR2)/push_swap
NAME3 = $(DIR3)/push_swap
NAME4 = $(DIR4)/push_swap
NAME5 = $(DIR5)/push_swap

# Run Target
RUN1 = ./$(NAME1) ; echo "\n\n"
RUN2 = ./$(NAME2) ; echo "\n\n"
RUN3 = ./$(NAME3) ; echo "\n\n"
RUN4 = ./$(NAME4) ; echo "\n\n"
RUN5 = ./$(NAME5) ; echo "\n\n"

# Default target
all : $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

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

# # Third Target
# 3 :
# 	make -C $(DIR3)
# $(NAME3) :
# 	make -C $(DIR3)
# 
# # Force Target
# 4 :
# 	make -C $(DIR4)
# $(NAME4) :
# 	make -C $(DIR4)
# 
# # Force Target
# 5 :
# 	make -C $(DIR5)
# $(NAME5) :
# 	make -C $(DIR5)

# Run Target
run :
	$(RUN1)
	$(RUN2)
	$(RUN3)
	$(RUN4)
	$(RUN5)

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

# Clean target
clean:
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

# Clean and remove target
fclean: clean

# Rebuild target
re: fclean all

.PHONY: all 1 2 3 4 fclean clean re run run1 run2 run3 run4 run5
