/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_bottom_side.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:09:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 20:04:04 by kamitsui         ###   ########.fr       */
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

void	recursive_bottom_side(
		t_stack *src, t_stack *tmp, t_range range, int original_tmp_top)
{
	debug_bottom_side(range);
	if (range.mode == MODE_REVERSE)
	{
		range.low = original_tmp_top + 1;
		range.high = tmp->top;
		range.mode = MODE_NORMAL;
		sort_quick(tmp, src, range);
	}
	else
	{
		instruct_px(tmp, src);
		range.high = src->top;
		sort_quick(src, tmp, range);
	}
}
//debug code
//recursive_bottom_side関数が走ったかデバッグ
//	debug_bottom_side(range);
