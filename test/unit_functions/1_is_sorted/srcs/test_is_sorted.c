/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 20:27:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "init.h"
#include "debug.h"
#include "ft_printf.h"
#include <stdbool.h>

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	bool	r;
	size_t	size;

	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments.\n");
		return (1);
	}
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements(&argv[1]);
	allocate_data(&stack_a, &stack_b, size);
	set_data(&stack_a, &argv[1], size);
	debug_data(&stack_a, &stack_b);
	r = is_sorted(&stack_a);
	ft_printf("\x1B[100m\x1B[37m");
	ft_printf("is_sorted [%d]", (int)r);
	ft_printf("\x1B[0m\n");
	free(stack_a.data);
	free(stack_b.data);
	system("leaks push_swap");
	return (0);
}
