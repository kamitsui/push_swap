/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/28 16:28:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief main function of push swap (this program to sort integer values)
 */
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "sort.h"
#include "error.h"
#include "ft_printf.h"
#include "debug.h"// debug

/**
 * @brief main function of push swap (this program to sort integer values)
 *
 * @param argc is number of integer values - 1
 * @param argv[] is array of integer-valued strings to sort
 *
 * @return 
 */
int main(int argc, char* argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	{
		ft_printf(MSG_ERR);
		return (1);
	}
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	if (argc > MAX_SIZE)
	{
		*stack_a.data = *allocate_array(argc - 1);
		*stack_b.data = *allocate_array(argc - 1);
	}
	set_data(&stack_a, argc, argv);
	debug_data(&stack_a, &stack_b);
	if (is_sorted(&stack_a))
	{
		ft_printf(MSG_IS_SORTED);
		return (0);
	}

	// At this point, the input is valid, and you can proceed with further processing
	// For example, you can call the push_swap function here
	// insert_sort(stack_a.data, stack_a.top + 1);// for array
	insert_sort(&stack_a, &stack_b);
	debug_data(&stack_a, &stack_b);
	if (argc > MAX_SIZE)
	{
		free(stack_a.data);
		free(stack_b.data);
	}
	// Don't forget to free the dynamically allocated memory
	system("leaks push_swap");
	return (0);
}
