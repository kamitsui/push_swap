/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/16 19:22:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

//デバッグ用
//#include "debug.h"// for debug
//#include "ft_printf.h"// debug
//int	g_fd_log;// debug
//int	g_flag_debug;//debug

// データを仕分けるヘルパー関数
// 小さいデータはtmpへpush、大きいデータはsrc内でrotate
static void	move_data(t_stack *src, t_stack *tmp,
		t_count *count, int pivot_data)
{
	if (is_less_than(src->data[src->top], pivot_data) == true)
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
//		if (g_flag_debug == 1)// debug
//			ft_dprintf(g_fd_log, "count->less++  [%d]\n", count->less);
//		if (g_flag_debug == 1)// debug
//			ft_dprintf(g_fd_log, "count->over++  [%d]\n", count->over);

// 大きい値を元に戻す作業 (stack_a のTOPに戻す）
static void	move_large_data(t_stack *src, t_count count)
{
	int	i;

	if (count.over != src->top)
	{
		i = 0;
		while (i < count.over + 1)
		{
			instruct_rrx(src);
			i++;
		}
	}
}

//例外処理
//　pivot_data以下の値がない時・・・分割できないため終了
//　逆順の場合・・・sort_reverseして終了
static int	handle_exception(t_stack *src, t_stack *tmp, t_range range)
{
	int	pivot_data;

	pivot_data = src->data[range.high];
	if (is_reverse_sorted_range(src, range.low, range.high) == true)
	{
		sort_reverse(src, tmp, range.high - range.low);
		return (1);
	}
	//if (range.high - range.low < 7)
	if (range.high - range.low == 2 && range.mode == MODE_NORMAL)
	{
		partition_three_elements(src, tmp, range);
		//partition_small(srcs, tmp, range);
		return (1);
	}
	return (0);
}
//partition関数に入った時の状態＋is_less_than...関数をデバッグ
//	if (g_flag_debug == 1)// debug
//		ft_dprintf(g_fd_log, ">> call partition function\n");
//sort_reverse関数を呼ぶ前のデバッグ
//		if (g_flag_debug == 1)// for debug
//			ft_dprintf(g_fd_log, ">> call sort_reverse func -- size[%d]\n",
//					range.high - range.low);
//sort_reverse関数の後のスタックをデバッグ
//		if (g_flag_debug == 1)// for debug
//			debug_data(g_fd_log, src, tmp);

void	partition(t_stack *src, t_stack *tmp, t_range range)
{
	int				pivot_data;
	int				size;
	int				i;
	t_count			count;
	t_transition	transition;

	if (handle_exception(src, tmp, range) == 1)
		return ;
	pivot_data = src->data[range.high];
	size = range.high - range.low;
	count.over = 0;
	count.less = 0;
	instruct_rx(src);
	i = 0;
	while (i < size)
	{
		set_transition(&transition, count, range, src);
		if (is_less_than_stack_range(src,
				transition.low, transition.high, pivot_data) == false)
			break ;
		move_data(src, tmp, &count, pivot_data);
		i++;
	}
	move_large_data(src, count);
}
//デバッグ用のフラグ
//	g_flag_debug = 1;
//breakするか否か？の状態確認
//		if (g_flag_debug == 1)// debug
//		{
//			ft_dprintf(g_fd_log, ">> low[%d] ~ high[%d] ... pivot_data[%d]\n",
//				src->data[offset + count.less],
//				src->data[range.high - count.less + count.over], pivot_data);
//			ft_dprintf(g_fd_log,
//				">> is_less_than_stack_range = [%d] false[%d] true[%d]\n",
//				is_less_than_stack_range(src, offset + count.over,
//				range.high - count.less + count.over, pivot_data),
//				true, false);
//		}
//
//move_dataする前の対象データを確認するコード
//		if (g_flag_debug == 1)// debug
//		{
//			ft_dprintf(g_fd_log,
//				">> is_less_than( %d , %d ) = [%d] true[%d] false[%d]\n",
//				src->data[src->top], pivot_data,
//				is_less_than(src->data[src->top], pivot_data), true, false);
//		}
