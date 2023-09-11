/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/11 21:00:00 by kamitsui         ###   ########.fr       */
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

	if (size < 7)
		sort_small(stack_a, stack_b, size);
	else
	{
		range.low = 0;
		range.high = stack_a->top;
		range.pi = stack_a->top;
		range.flag = BIT_UNSORTED;
		sort_quick(stack_a, stack_b, range);
	}
}
