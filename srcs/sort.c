/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 18:23:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	sort(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_range	range;
	t_count	count;

	if (size < 7)
		sort_small(stack_a, stack_b, size, BOTTOM_SIDE);
	else
	{
		range.low = 0;
		range.high = stack_a->top;
		range.mode = BOTTOM_SIDE;
		init_count(&count);
		sort_quick(stack_a, stack_b, range, count);
	}
}
