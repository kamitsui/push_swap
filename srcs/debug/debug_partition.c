/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_partition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:04:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 21:49:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "debug.h"
#include "ft_printf.h"

//partition関数の開始状況をデバッグ
void	debug_partition_start(int mode)
{
	if (g_flag_debug == 1)// debug
		ft_dprintf(g_fd_log, ">> call partition function ... mode [%d]\
\x9	\x9	\x9	 ... bottom[%d] top[%d]\n", mode, BOTTOM_SIDE, TOP_SIDE);
}

//transition関数のあとのレンジをデバッグ
void	debug_after_transition(t_range range)
{
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log,
			">> after transition low = %d  high = %d\n",
			range.transition_low, range.transition_high);
}

//デバッグ対象のデータ　現在のデータ　最新のminデータ　pivotデータ　breakの判断
void	debug_current_data(t_stack *src, t_range range)
{
	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log,
			">> min_data = %d  src->data[top] = %d  pivot= %d\n", range.min_data,
			src->data[src->top], range.pivot_data);
		if (range.mode == TOP_SIDE)
		{
			ft_dprintf(g_fd_log,
				">> is_more_than_stack ? = %d  low %d ~ high %d\n",
				is_more_than_stack_range(src,
				range.transition_low, range.transition_high, range.pivot_data),
				range.transition_low, range.transition_high);
		}
		else
		{
			ft_dprintf(g_fd_log,
				">> is_less_than_stack ? = %d  low %d ~ high %d\n",
				is_less_than_stack_range(src,
				range.transition_low, range.transition_high, range.pivot_data),
				range.transition_low, range.transition_high);
		}
	}
}
