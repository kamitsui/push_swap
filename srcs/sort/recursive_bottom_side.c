/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_bottom_side.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:09:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 22:01:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"

// for debug
#include "debug.h"

void	recursive_bottom_side(t_stack *src, t_stack *tmp,
		t_range range, t_count count)
{
	if (range.mode == TOP_SIDE)
	{
		range.low = tmp->top - count.over + 1;
		range.high = tmp->top;
		range.mode = BOTTOM_SIDE;
		init_count(&count);
		sort_quick(tmp, src, range, count);
	}
	else
	{
		range.low = src->top - count.over + 1;
		range.high = src->top;
		init_count(&count);
		sort_quick(src, tmp, range, count);
	}
}

//debug code
//		debug_recursivt(range);
//		debug_before_range(range);
//		debug_after_range(range);
