/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:11:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief main function of push swap (this program to sort integer values)
 */
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "init.h"
#include "sort.h"
#include "error.h"
#include "ft_printf.h"
#include "debug.h"// debug

static void	free_stack(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	if (size > BUFF_SIZE)
	{
		free(stack_a->data);
		free(stack_b->data);
	}
}

/**
 * @brief main function of push swap (this program to sort integer values)
 *
 * @param argc is number of integer values - 1
 * @param argv[] is array of integer-valued strings to sort
 *
 * @return 
 */
int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		data_a[BUFF_SIZE];
	int		data_b[BUFF_SIZE];
	size_t	size;

	if (argc < 2)
		return (1);
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements(&argv[1]);
	if (size > BUFF_SIZE)
		allocate_data(&stack_a, &stack_b, size);
	else
	{
		stack_a.data = &data_a[0];
		stack_b.data = &data_b[0];
	}
	set_data(&stack_a, &argv[1], size);
	if (is_sorted(&stack_a))
		handle_error(ERR_NUM);
	insert_sort(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b, size);
	return (0);
}
//	debug_data(&stack_a, &stack_b);// for debug
//	debug_data(&stack_a, &stack_b);// for debug
//	system("leaks push_swap");// for debug
