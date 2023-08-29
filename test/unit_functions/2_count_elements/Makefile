# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/29 14:42:53 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = a.out

# Sources files
SRCS = count_elements.c\
	   test_count_elements.c

# Directories
PROJ_DIR = ../../..
SRCS_DIR = $(PROJ_DIR)/srcs/init_utils \
		   srcs
OBJS_DIR = obj
DEPS_DIR = .dep

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
	$(CC) $(CFLAGS) $(INC) $(DEP_CF) -c $< -o $@
#	$(CC) $(CFLAGS) $(INC) $(DEP_CF) $(LD_CF) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME)

# Mandatory Target
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIB_PRINTF) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS) $(LIB_PRINTF) -o $(NAME)

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
	./run.sh

# Enable dependency file
-include $(DEPS)

.PHONY: debug all clean fclean re run
