/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/08 15:08:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "debug.h"//debug
#include "ft_printf.h"//debug

int	fd_log;//debug

void	sort(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_range	range;
	bool	flag_sorted;

	if (size < 7)
		sort_small(stack_a, stack_b, size);
	else
	{
		range.low = 0;
		range.high = stack_a->top;
		range.pi = stack_a->top;
		flag_sorted = false;

		range.flag_sorted = &flag_sorted;
//		ft_dprintf(fd_log, "flag_sorted pointer [%p]\n", range.flag_sorted);
		sort_quick(stack_a, stack_b, range);
	}
		//sort_six_elements(stack_a, stack_b);
}
