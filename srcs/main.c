/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/08 09:19:31 by kamitsui         ###   ########.fr       */
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
#include <fcntl.h>// debug

int	fd_log; // for debug
int	flag_debug; // debug

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
	fd_log = open_log("debug.log", O_TRUNC); // for debug
	flag_debug = 0;// debug

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
	debug_data(fd_log, &stack_a, &stack_b);// for debug
	if (is_sorted(&stack_a) == false)
		sort(&stack_a, &stack_b, size);
	debug_data(fd_log, &stack_a, &stack_b);// for debug
	free_stack(&stack_a, &stack_b, size);
	close (fd_log);// for debug
	return (0);
}
//	system("leaks push_swap");// for debug
