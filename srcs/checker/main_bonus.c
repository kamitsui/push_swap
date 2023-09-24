/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 18:43:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main_bonus.c
 * @brief main function of checker
 */
#include <stdlib.h>
#include "push_swap.h"
#include "init.h"
#include "error.h"
#include "checker.h"

/**
 * @brief main function of checker
 * @details
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
	t_stack	stack_a;
	t_stack	stack_b;
//	int		data_a[MAX_SIZE];
//	int		data_b[MAX_SIZE];
	size_t	size;

	if (argc < 2)
		return (1);
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements(&argv[1]);
//	if (size > MAX_SIZE)
		allocate_data(&stack_a, &stack_b, size);
//	else
//	{
//		stack_a.data = &data_a[0];
//		stack_b.data = &data_b[0];
//	}
	set_data(&stack_a, &argv[1], size);
	stack_a.size = stack_a.top;
	stack_b.size = stack_a.size;;
	return (checker(&stack_a, &stack_b));
}
