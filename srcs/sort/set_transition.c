/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:51:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/23 18:26:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	set_transition(t_transition *transition,
			t_count count, t_range range, t_stack *src, t_stack *tmp)
{
	if (range.mode == MODE_REVERSE)
	{
		transition->low = range.low + count.less;
		transition->high = src->top;
	}
	else
	{
		//transition->low = range.low + count.over;// 9/23以前
		transition->low = range.low + count.over + count.min;
		//(void)tmp;
		if (tmp->top + 1 > count.less)// 9/23 検証
			transition->low -= (tmp->top + 1 - count.less);
		//transition->high = range.high - count.less - count.min + count.over;
		transition->high = src->top;// 実験　上の式でなくてもいいのでは？9/22
	}
}

