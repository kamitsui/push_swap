# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/20 19:57:06 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME1 = find_pivot
NAME2 = find_median

# Sources files
SRCS1 = find_pivot.c
SRCS2 = find_median.c

# Directories
SRCS_DIR = \
		   srcs
OBJS_DIR = objs
DEPS_DIR = .deps
PROJ_DIR = ../..

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR)

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
OBJS1 = $(addprefix $(OBJS_DIR)/, $(SRCS1:.c=.o))
DEPS1 = $(addprefix $(DEPS_DIR)/, $(SRCS1:.c=.d))
OBJS2 = $(addprefix $(OBJS_DIR)/, $(SRCS2:.c=.o))
DEPS2 = $(addprefix $(DEPS_DIR)/, $(SRCS2:.c=.d))

# Rules for building object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INC) $(DEP_CF) -c $< -o $@
#	$(CC) $(CFLAGS) $(INC) $(DEP_CF) $(LD_CF) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME1) $(NAME2)

# Mandatory Target
1: $(NAME1)
$(NAME1): $(LIBFT) $(LIB_PRINTF) $(OBJS1)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS1) $(LIB_PRINTF) -o $(NAME1)
#	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS) -o $(NAME1)

2: $(NAME2)
$(NAME2): $(LIBFT) $(LIB_PRINTF) $(OBJS2)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS2) $(LIB_PRINTF) -o $(NAME2)
#	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS) -o $(NAME2)

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
	rm -f $(NAME1) $(NAME2)

# Rebuild target
re: fclean all

# Run test
run:
run1:
	./$(NAME1)
run2:
	./$(NAME2)

# Enable dependency file
-include $(DEPS)

.PHONY: debug all clean fclean re run run1 run2 1 2
