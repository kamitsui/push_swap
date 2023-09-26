/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:07:47 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 20:29:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "quick_sort.h"
#include <stdbool.h>

// for debug
#include "debug.h"

// bottom側データを仕分ける関数
// 小さいデータはsrc内でrotate、大きいデータはtmpへpush
static void	move_data_top_side(
		t_stack *src, t_stack *tmp, t_count *count, t_range range)
{
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
static void	move_data_bottom_side(t_stack *src, t_stack *tmp,
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
			instruct_rx(src);
		count->min++;
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

// debug code
//	debug_move_data(range.min_data, src->data[src->top], range.mode);
//		debug_count_min(count->min);
//		debug_count_less(count->less);
//		debug_count_over(count->over);
