/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_top_side.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:24:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:51:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "init.h"

// for debug
#include "debug.h"

void	recursive_top_side(
		t_stack *src, t_stack *tmp, t_range range, t_count count)
{
	if (range.mode == TOP_SIDE)
	{
		range.low = 0;
		range.high = src->top;
		init_count(&count);
		sort_quick(src, tmp, range, count);
	}
	else
	{
		range.low = 0;
		range.high = tmp->top;
		range.mode = TOP_SIDE;
		init_count(&count);
		sort_quick(tmp, src, range, count);
	}
}
//debug code
//	debug_recursive(range);
//		debug_before_range(range);
//		debug_after_range(range);
