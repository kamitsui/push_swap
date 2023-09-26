/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_manual_sort_using_partition.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 17:46:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "init.h"
#include "debug.h"
#include "sort.h"
#include <stdlib.h>
#include <unistd.h>

void	manual_sort(t_stack *stack_a, t_stack *stack_b, t_count *count)
{
	t_range	range;
	bool	flag_sorted;
	int		pi;

	pi = 0;
	range.low = 0;
	range.high = stack_a->top;
	flag_sorted = false;

// first
//	ft_printf("\n--- first ---\n");
//	pi = partition(stack_a, stack_b, range, &flag_sorted);
	partition(stack_a, stack_b, range, count);
//	int pi_1th = pi;
//	ft_printf("low[%d] high[%d] pi[%d] pivot[%d] flag_sorted[%d]\n",
//			range.low, range.high, pi, stack_a->data[pi], flag_sorted);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);// for debug

// bottom side
//	ft_printf("\n--- bottom side ---\n");
//	range.high = pi - 1;
//	pi = partition(stack_a, stack_b, range, &flag_sorted);
	range.transition_high = pi - 1;
	partition(stack_a, stack_b, range, count);
//	ft_printf("low[%d] high[%d] pi[%d] pivot[%d] flag_sorted[%d]\n",
//			range.low, range.high, pi, stack_a->data[pi], flag_sorted);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);// for debug

// bottom-side's top side
//	ft_printf("\n--- bottom-side's - top side ---\n");
	//high = pi - 1;// lower's (pi - 1)
//	range.low = pi + 1;
//	pi = partition(stack_a, stack_b, range, &flag_sorted);
	range.transition_low = pi + 1;
	partition(stack_a, stack_b, range, count);
//	ft_printf("low[%d] high[%d] pi[%d] pivot[%d] flag_sorted[%d]\n",
//			range.low, range.high, pi, stack_a->data[pi], flag_sorted);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);// for debug

// top side
//	ft_printf("\n--- top side ---\n");
//	range.low = pi_1th + 1;
//	range.high = stack_a->top;
//	pi = partition(stack_a, stack_b, range, &flag_sorted);
//	ft_printf("low[%d] high[%d] pi[%d] pivot[%d] flag_sorted[%d]\n",
//			range.low, range.high, pi, stack_a->data[pi], flag_sorted);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);// for debug

// top-side's - bottom side
//	ft_printf("\n--- top-side's - bottom side ---\n");
//	range.high = pi - 1;
//	pi = partition(stack_a, stack_b, range, &flag_sorted);
//	ft_printf("low[%d] high[%d] pi[%d] pivot[%d] flag_sorted[%d]\n",
//			range.low, range.high, pi, stack_a->data[pi], flag_sorted);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);// for debug

// top-side's - bottom-side's - bottom side
//	ft_printf("\n--- top-side's - bottom-side's - bottom side ---\n");
//	range.high = pi - 1;
//	pi = partition(stack_a, stack_b, range, &flag_sorted);
//	ft_printf("low[%d] high[%d] pi[%d] pivot[%d] flag_sorted[%d]\n",
//			range.low, range.high, pi, stack_a->data[pi], flag_sorted);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);// for debug

// top-side's - bottom-side's - bottom-side's - bottom side
//	ft_printf("\n--- top-side's - bottom-side's - bottom-side's - bottom side ---\n");
//	range.high = pi - 1;
//	pi = partition(stack_a, stack_b, range, &flag_sorted);
//	ft_printf("low[%d] high[%d] pi[%d] pivot[%d] flag_sorted[%d]\n",
//			range.low, range.high, pi, stack_a->data[pi], flag_sorted);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);// for debug
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_count	count;
	size_t	size;

	size = count_elements(&argv[1]);
	init_stack(&stack_a, &stack_b, size);
	allocate_data(&stack_a, &stack_b, size);
	set_data(&stack_a, &argv[1], size);
	ft_printf("--- before ---\n");
	debug_data(STDOUT_FILENO, &stack_a, &stack_b);// for debug
	if (is_sorted(&stack_a) == true)
		return (0);
	init_count(&count);
	manual_sort(&stack_a, &stack_b, &count);
	ft_printf("--- after ---\n");
	debug_data(STDOUT_FILENO, &stack_a, &stack_b);// for debug
	ft_printf("is_sorted? [%d]  true[%d] false[%d]\n", is_sorted(&stack_a), true, false);
	free_stack(&stack_a, &stack_b);
	(void)argc;
	return (0);
}
