/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:51:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 14:35:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quick_sort.h"

void	set_transition(t_stack *src, t_stack *tmp,
		t_count count, t_range *range)
{
	if (range->mode == TOP_SIDE)
	{
		range->transition_low = range->low + count.less;
		range->transition_high = src->top;
	}
	else
	{
		range->transition_low = range->low + count.over + count.min;
		if (tmp->top + 1 > count.less)
			range->transition_low -= (tmp->top + 1 - count.less);
		range->transition_high = src->top;
	}
}
