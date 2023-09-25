/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_bottom_side.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:09:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 18:24:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"

// for debug
#include "debug.h"
#include "ft_printf.h"

int	g_fd_log;
int	g_flag_debug;

// debug function
static void	debug_bottom_side(t_range range)
{
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log,
			">> call recursive sort_quick func -- bottom side -- \
\x9	\x9	\x9	from mode[%d]\n",
			range.mode);
}

void	recursive_bottom_side(t_stack *src, t_stack *tmp,
		t_range range, t_count count)
{
//	debug_bottom_side(range);
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
		debug_bottom_side(range);
		debug_before_range(range);
		range.low = src->top - count.over + 1;
		range.high = src->top;
		init_count(&count);
		debug_after_range(range);
		sort_quick(src, tmp, range, count);
	}
}
//debug code
//recursive_bottom_side関数が走ったかデバッグ
//	debug_bottom_side(range);
