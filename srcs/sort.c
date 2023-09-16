/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/16 18:00:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	sort(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_range	range;

	if (size < 7)
		sort_small(stack_a, stack_b, size, MODE_NORMAL);
	else
	{
		range.low = 0;
		range.high = stack_a->top;
		range.mode = MODE_NORMAL;
		sort_quick(stack_a, stack_b, range);
	}
}
