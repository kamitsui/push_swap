/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:07:47 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 18:18:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

//デバッグ用
#include "debug.h"// for debug
#include "ft_printf.h"// debug

// bottom側データを仕分ける関数
// 小さいデータはsrc内でrotate、大きいデータはtmpへpush
void	move_data_top_side(t_stack *src, t_stack *tmp,
//		t_count *count, int pivot_data, int min_data)
		t_count *count, t_range range)
{
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log,
			">>in move_data min_data = %d  src->data[top] = %d\n",
			range.min_data, src->data[src->top]);
	if (src->data[src->top] == range.min_data)
	{
		instruct_px(tmp, src);
		instruct_rx(tmp);
		count->min++;
	}
	else if (is_less_than(src->data[src->top], range.pivot_data) == true
			|| src->data[src->top] == range.pivot_data)
	{
		instruct_rx(src);
		count->less++;
	}
	else
	{
		instruct_px(tmp, src);
		count->over++;
	}
}

// top側のデータを仕分ける関数
// 小さいデータはtmpへpush、大きいデータはsrc内でrotate
void	move_data_bottom_side(t_stack *src, t_stack *tmp,
		t_count *count, t_range range)
{
	if (src->data[src->top] == range.min_data)
	{
		if (count->over > 0)
		{
			instruct_px(tmp, src);
			instruct_rx(tmp);
		}
		else
		{
			instruct_rx(src);// 9/23 検証
		}
		count->min++;
//		if (g_flag_debug == DEBUG_ON)
//			ft_dprintf(g_fd_log, ">> count->min++ [%d]\n", count->min);
	}
	else if (is_less_than(src->data[src->top], range.pivot_data) == true
			|| src->data[src->top] == range.pivot_data)
	{
		instruct_px(tmp, src);
		count->less++;
	}
	else
	{
		instruct_rx(src);
		count->over++;
//		if (g_flag_debug == DEBUG_ON)
//			ft_dprintf(g_fd_log, ">> count->over++ [%d]\n", count->over);
	}
}

void	move_data(t_stack *src, t_stack *tmp,
		t_count *count, t_range range)
{
	if (range.mode == TOP_SIDE)
		move_data_top_side(src, tmp, count, range);
	else
		move_data_bottom_side(src, tmp, count, range);
}
