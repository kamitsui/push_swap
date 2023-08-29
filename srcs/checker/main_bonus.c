/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 22:15:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main_bonus.c
 * @brief main function of checker
 */
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "push_swap.h"
#include "init.h"
#include "sort.h"
#include "error.h"
#include "checker.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "debug.h"// debug

/**
 * @brief main function of checker
 * @detail
 * checker read instructions on the standard input,\n
 * and execute those instructions.\n
 * stack a is sorted and stack b is empty,\n
 * then the program must display "OK\n" on the standard output.\n
 * In every other case, it must display "KO\n" on the standard output.\n
 *
 * @param argc is number of command arguments
 * @param argv[] is array of integer-valued strings to sort
 *
 * @return 0:success 1:failure
 */
int	main(int argc, char *argv[])
{
	size_t	i;

	// Initialize stacks and other variables here
	//char	instruction[MAX_INSTRUCTION_LENGTH + 1]; // +1 for null terminator
	char	*instruction[1024];

	i = 0;
	while (true)
	{
		instruction[i] = get_next_line(STDIN_FILENO);
		if (instruction[i] == NULL)
			break ;
		// Execute the instruction on the stacks here
		// Check if the stacks are sorted and empty
		//if (is_sorted(stack_a) && is_empty(stack_b))
		//	ft_printf("OK\n");
		//else
		//	ft_printf("KO\n");
		// Optional: Add a condition to break the loop if you're done reading instructions
		i++;
	}
	i = 0;
	while (instruction[i] != NULL)
	{
		ft_printf("instruction[%d] [%s]\n", i, instruction[i]);
		i++;
	}
	(void)argv[argc];
	return (0);
}
//
//int main(int argc, char* argv[])
//{
//	t_stack	stack_a;
//	t_stack	stack_b;
//	int		data_a[BUFF_SIZE];
//	int		data_b[BUFF_SIZE];
//
//	if (argc < 2)
//		return (1);
//	init_stack(&stack_a, (char *)"a");
//	init_stack(&stack_b, (char *)"b");
//	if (argc > BUFF_SIZE)
//		allocate_data(&stack_a, &stack_b, argc - 1);
//	else
//	{
//		stack_a.data = &data_a[0];
//		stack_b.data = &data_b[0];
//	}
//	set_data(&stack_a, argc, argv);
//	debug_data(&stack_a, &stack_b);
//	if (is_sorted(&stack_a))
//		handle_error(ERR_NUM);
//	insert_sort(&stack_a, &stack_b);
//	debug_data(&stack_a, &stack_b);
//	if (argc > BUFF_SIZE)
//	{
//		free(stack_a.data);
//		free(stack_b.data);
//	}
//	system("leaks push_swap");// for debug
//	return (0);
//}
