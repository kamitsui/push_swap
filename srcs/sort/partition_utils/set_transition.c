/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:51:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 21:05:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

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

//void	set_transition(t_transition *transition,
//			t_count count, t_range range, t_stack *src, t_stack *tmp)
//{
//	if (range.mode == TOP_SIDE)
//	{
//		transition->low = range.low + count.less;
//		transition->high = src->top;
//	}
//	else
//	{
//		transition->low = range.low + count.over + count.min;
//		if (tmp->top + 1 > count.less)
//			transition->low -= (tmp->top + 1 - count.less);
//		transition->high = src->top;
//	}
//}
