# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/23 14:13:11 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME1 = 1_insert_sort

# Sources files
SRCS1 = insert_sort.c
SRCS2 = 

# Directories
SRCS_DIR = \
		   srcs
OBJS_DIR = obj
DEPS_DIR = .dep

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
DEPS = $(addprefix $(DEPS_DIR)/, $(SRCS1:.c=.d))
OBJS2 = $(addprefix $(OBJS_DIR)/, $(SRCS2:.c=.o))
DEPS = $(addprefix $(DEPS_DIR)/, $(SRCS2:.c=.d))

# Rules for building object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INC) $(DEP_CF) -c $< -o $@
#	$(CC) $(CFLAGS) $(INC) $(DEP_CF) $(LD_CF) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME1)

# Mandatory Target
1:
	make
$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS1) -o $(NAME1)
#	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS1) -o $(NAME1)

# Clean target
clean:
	rm -rf $(OBJS_DIR) $(DEPS_DIR)

# Clean and remove target
fclean: clean
	rm -f $(NAME1)

# Rebuild target
re: fclean all

# Run test
run1:
	./$(NAME1)

# Enable dependency file
-include $(DEPS)

.PHONY: debug all clean fclean re 1 run run1
