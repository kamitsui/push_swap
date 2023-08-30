/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 10:16:58 by kamitsui         ###   ########.fr       */
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
	size_t				i;
	char				*instruction;
	enum e_instruction	type;

	// Initialize stacks and other variables here
	//char	instruction[MAX_INSTRUCTION_LENGTH + 1]; // +1 for null terminator

	i = 0;
	while (true)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (instruction == NULL)
			break ;
		type = search_type_instruction(instruction);
		// Execute the instruction on the stacks here
		// Check if the stacks are sorted and empty
		//if (is_sorted(stack_a) && is_empty(stack_b))
		//	ft_printf("OK\n");
		//else
		//	ft_printf("KO\n");
		// Optional: Add a condition to break the loop if you're done reading instructions
		ft_printf("%s %d", instruction, (int)type);
		free(instruction);
		i++;
	}
	(void)argv[argc];
	return (0);
}
