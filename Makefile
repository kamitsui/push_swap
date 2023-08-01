# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 16:07:25 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/01 16:13:12 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 13:59:50 by kamitsui          #+#    #+#              #
#    Updated: 2023/07/31 13:51:04 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = push_swap

# Libraries
LIB_PRINTF_DIR = ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Include Header
INC_DIR = include

# Sources
SRC_DIR = src
SRCS = \
	   main.c \
	   init.c \
	   debug.c

# vpath for serching source files in multiple directories
vpath %.c $(SRC_DIR)

# Objects
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Dependency files
DEP_DIR = .dep
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Compile
CC = clang
CF = -Wall -Wextra -Werror
#CF = -Wall -Wextra -Werror -fsanitize=address -g#error ld: symbol not found
INC_CF = -I$(INC_DIR)
DEP_CF = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CF) $(INC_CF) $(DEP_CF) -c $< -o $@

# Rules for building dependency files
$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: $(NAME)

# Target
$(NAME): $(DEPS) $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
#$(NAME): $(LIB_PRINTF) $(DEPS) $(OBJS)
#	$(CC) -o $(NAME) $(OBJS) $(LIB_PRINTF)

# Library target
#$(LIB_PRINTF): $(LIBFT)
#	$(MAKE) -C $(LIB_PRINTF_DIR)
#$(LIBFT):
#	$(MAKE) -C $(LIBFT_DIR)

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
