# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 16:07:25 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/24 18:39:59 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = push_swap
NAME_B = checker

# Libraries
LIBFT_DIR = libft
LIB_PRINTF_DIR = ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Include Header
INC_DIR = includes

# Sources
SRC_DIR = \
		  srcs \
		  srcs/init_utils \
		  srcs/is_utils \
		  srcs/instruct \
		  srcs/sort \
		  srcs/debug \
		  srcs/checker \
		  srcs/checker/is_instruction
SRCS = \
	   main.c \
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
	   set_transition.c \
	   get_pivot_data.c \
	   get_min_data.c \
	   allocate_array.c \
	   move_min_data.c \
	   \
	   is_less_than.c \
	   is_more_than.c \
	   is_less_than_stack_range.c \
	   is_more_than_stack_range.c \
	   is_sorted.c \
	   is_sorted_range.c \
	   is_reverse_sorted_range.c \
	   is_empty.c \
	   is_full.c \
	   \
	   error.c \
	   \
	   debug_data.c \
	   repeat_push.c \
	   repeat_swap.c \
	   open_log.c \
	   debug_sort_quick.c \
	   debug_range.c \
	   debug_array.c
SRCS_B = \
		 main_bonus.c \
		 \
		 checker.c \
		 \
		 search_type_instruction.c \
		 \
		 is_instruction_rrr.c \
		 is_instruction_rra.c \
		 is_instruction_rrb.c \
		 is_instruction_rr.c \
		 is_instruction_ra.c \
		 is_instruction_rb.c \
		 is_instruction_pa.c \
		 is_instruction_pb.c \
		 is_instruction_sa.c \
		 is_instruction_sb.c \
		 is_instruction_ss.c \
		 is_instruction_error.c \
		 \
		 execute_instruction.c

# vpath for serching source files in multiple directories
vpath %.c $(SRC_DIR)

# Objects
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_FILTER = $(addprefix $(OBJ_DIR)/, main.o)
OBJS_B = $(filter-out $(OBJS_FILTER), \
		 $(addprefix $(OBJ_DIR)/, $(SRCS_B:.c=.o)) $(OBJS))

# Dependency files
DEP_DIR = .deps
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))
DEPS_B = $(addprefix $(DEP_DIR)/, $(SRCS_B:.c=.d))

# Compile
CC = cc
CF = -Wall -Wextra -Werror
LD_CF = -g -fsanitize=address
INC_CF = -I$(INC_DIR)
DEP_CF = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)
ifdef WITH_ASAN
CF += $(LD_CF)
endif

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CF) $(INC_CF) $(DEP_CF) -c $< -o $@
#	$(CC) $(CF) $(INC_CF) $(DEP_CF) -c $< -o $@ $(LD_CF)

# Rules for building dependency files
$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: $(NAME)

# Target
$(NAME): $(LIB_PRINTF) $(DEPS) $(OBJS)
	$(CC) $(CF) $(OBJS) $(LIB_PRINTF) -o $(NAME)

# Library target
$(LIB_PRINTF): $(LIBFT)
	make -C $(LIB_PRINTF_DIR)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Bonus target
bonus: all $(NAME_B)

# Checker
$(NAME_B): $(LIB_PRINTF) $(DEPS) $(OBJS_B)
	$(CC) $(CF) $(OBJS_B) $(LIB_PRINTF) -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

# Clean and remove target
fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIB_PRINTF_DIR)
	rm -f $(NAME) $(NAME_B)

# Rebuild target
re: fclean all

# Address Sanitizer ON
asan: fclean
	make asan -C $(LIBFT_DIR)
	make asan -C $(LIB_PRINTF_DIR)
	make $(NAME) WITH_ASAN=1
	make bonus WITH_ASAN=1

# Enable dependency file
-include $(DEPS)

.PHONY: all clean fclean re bonus asan
