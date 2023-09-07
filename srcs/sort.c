/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/07 20:43:53 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

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
		range.flag_sorted = false;
		sort_quick(stack_a, stack_b, range);
	}
		//sort_six_elements(stack_a, stack_b);
}
