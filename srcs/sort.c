/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 17:06:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "init.h"
#include "sort.h"
#include "quick_sort.h"

void	sort(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_range	range;
	t_count	count;

	if (size < 7)
		sort_small(stack_a, stack_b, size);
	else
	{
		range.low = 0;
		range.high = stack_a->top;
		range.mode = BOTTOM_SIDE;
		init_count(&count);
		sort_quick(stack_a, stack_b, range, count);
	}
}
