# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 16:07:25 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/29 11:41:42 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = push_swap

# Libraries
LIB_PRINTF_DIR = ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Include Header
INC_DIR = includes

# Sources
SRC_DIR = srcs \
		  srcs/init_utils \
		  srcs/instruct \
		  srcs/sort \
		  srcs/debug
SRCS = \
	   main.c \
	   \
	   init_stack.c \
	   count_number_data.c \
	   allocate_data.c \
	   set_data.c \
	   \
	   push.c \
	   swap.c \
	   rotate.c \
	   reverse_rotate.c \
	   \
	   operation.c \
	   stack_utils.c \
	   \
	   insert_sort.c \
	   \
	   is_less_than.c \
	   \
	   error.c \
	   \
	   debug_data.c \
	   repeat_push.c \
	   repeat_swap.c \
	   repeat_rotate.c \
	   repeat_reverse_rotate.c

# vpath for serching source files in multiple directories
vpath %.c $(SRC_DIR)

# Objects
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Dependency files
DEP_DIR = .deps
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Compile
CC = cc
CF = -Wall -Wextra -Werror
LDF = -g -fsanitize=address
INC_CF = -I$(INC_DIR)
DEP_CF = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CF) $(INC_CF) $(DEP_CF) -c $< -o $@
#	$(CC) $(CF) $(INC_CF) $(DEP_CF) -c $< -o $@ $(LDF)

# Rules for building dependency files
$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: $(NAME)

# Target
$(NAME): $(LIB_PRINTF) $(DEPS) $(OBJS)
	$(CC) $(CF) $(OBJS) $(LIB_PRINTF) -o $(NAME)
#	$(CC) $(CF) $(OBJS) $(LIB_PRINTF) -o $(NAME) $(LDF)

# Library target
$(LIB_PRINTF): $(LIBFT)
	make -C $(LIB_PRINTF_DIR)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

# Clean and remove target
fclean: clean
	rm -f $(NAME)

# Rebuild target
re: fclean all

# Enable dependency file
-include $(DEPS)

.PHONY: all clean fclean re# bonus
