# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/16 19:20:41 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = push_swap

# Sources files
SRCS = \
	   test_sort_quick.c \
	   \
	   \
	   free_stack.c \
	   \
	   init_stack.c \
	   count_elements.c \
	   allocate_data.c \
	   set_data.c \
	   \
	   instruct_push.c \
	   instruct_rotate.c \
	   instruct_swap.c \
	   \
	   execute_reverse_rotate.c \
	   execute_rotate.c \
	   execute_swap.c \
	   execute_push.c \
	   \
	   operation.c \
	   \
	   sort.c \
	   sort_small.c \
	   sort_two_elements.c \
	   sort_three_elements.c \
	   sort_six_elements.c \
	   sort_insert.c \
	   sort_quick.c \
	   recursive_top_side.c \
	   recursive_bottom_side.c \
	   end_process.c \
	   partition.c \
	   partition_reverse.c \
	   partition_small.c \
	   sort_reverse.c \
	   \
	   is_less_than.c \
	   is_more_than.c \
	   is_less_than_stack_range.c \
	   is_more_than_stack_range.c \
	   is_reverse_sorted_range.c \
	   is_sorted.c \
	   is_sorted_range.c \
	   is_empty.c \
	   is_full.c \
	   \
	   debug_data.c \
	   open_log.c \
	   debug_range.c \
	   debug_sort_quick.c \
	   \
	   error.c



# Directories
PROJ_DIR = ../../..
SRCS_DIR = \
		   $(PROJ_DIR)/srcs \
		   $(PROJ_DIR)/srcs/init_utils \
		   $(PROJ_DIR)/srcs/sort \
		   $(PROJ_DIR)/srcs/is_utils \
		   $(PROJ_DIR)/srcs/instruct \
		   $(PROJ_DIR)/srcs/debug \
		   srcs
OBJS_DIR = objs
DEPS_DIR = .deps

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR) $(SRCS_B_DIR)

# Libraries
LIBFT_DIR = $(PROJ_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF_DIR = $(PROJ_DIR)/ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a


# Compile
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-lreadline
DEP_CF		=	-MMD -MP -MF $(@:$(OBJS_DIR)/%.o=$(DEPS_DIR)/%.d)
LD_CF = -g -fsanitize=address
INC = -I$(PROJ_DIR)/includes

# Object files and dependency files
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d))

# Rules for building object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(DEPS_DIR)
#	$(CC) $(CFLAGS) $(INC) $(DEP_CF) -c $< -o $@
	$(CC) $(CFLAGS) $(INC) $(DEP_CF) $(LD_CF) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME)

# Mandatory Target
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS)
#	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIB_PRINTF) -o $(NAME)
	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS) $(LIB_PRINTF) -o $(NAME)

# Library target
$(LIB_PRINTF): $(LIBFT)
	make -C $(LIB_PRINTF_DIR)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean target
clean:
	rm -rf $(OBJS_DIR) $(DEPS_DIR)

# Clean and remove target
fclean: clean
	rm -f $(NAME)

# Rebuild target
re: fclean all

# Run test
run:
	./run1.sh
	./run2.sh
	./run3.sh
	./run4.sh
	./run5.sh
	./run6.sh
	./run7.sh
	./run8.sh
	./run9.sh
	./run10.sh
	./run11.sh
	./run12.sh
	./run13.sh
	./run14.sh
run1:
	./run1.sh
run2:
	./run2.sh
run3:
	./run3.sh
run4:
	./run4.sh
run5:
	./run5.sh
run6:
	./run6.sh
run7:
	./run7.sh
run8:
	./run8.sh
run9:
	./run9.sh
run10:
	./run10.sh
run11:
	./run11.sh
run12:
	./run12.sh
run13:
	./run13.sh
run14:
	./run14.sh

# Enable dependency file
-include $(DEPS)

.PHONY: debug all clean fclean re run run1 run2 run3 run4 run5 run6 run7 run8 run9 run10 run11 run12 run13 run14
