/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_quick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/05 19:22:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "init.h"
#include "debug.h"
#include "sort.h"
#include <stdlib.h>

void	sort_quick_dev(t_stack *stack_a, t_stack *stack_b, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(stack_a, stack_b, low, high);
		ft_printf("pi[%d]\n", pi);
		sort_quick(stack_a, stack_b, pi + 1, high);
//		sort_quick(stack_a, stack_b, low, pi - 1);
	}
}


int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	size_t	size;
	int		pi;

	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements(&argv[1]);
	allocate_data(&stack_a, &stack_b, size);
	set_data(&stack_a, &argv[1], size);
	ft_printf("--- before ---\n");
	debug_data(&stack_a, &stack_b);// for debug
	pi = 0;
	if (is_sorted(&stack_a) == false)
		sort_quick_dev(&stack_a, &stack_b, 0, stack_a.top);
	ft_printf("--- after ---\n");
	debug_data(&stack_a, &stack_b);// for debug
	free_stack(&stack_a, &stack_b, size);
	(void)argc;
	return (0);
}
