/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:51:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/22 14:21:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	set_transition(t_transition *transition,
			t_count count, t_range range, t_stack *src)
{
	if (range.mode == MODE_REVERSE)
	{
		transition->low = range.low + count.less;
		transition->high = src->top;
	}
	else
	{
		transition->low = range.low + count.over;
		//transition->high = range.high - count.less - count.min + count.over;
		transition->high = src->top;// 実験　上の式でなくてもいいのでは？9/22
	}
}

