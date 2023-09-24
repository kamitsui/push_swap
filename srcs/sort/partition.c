/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 18:25:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

//デバッグ用
#include "debug.h"// for debug
#include "ft_printf.h"// debug

int	g_fd_log;// debug
int	g_flag_debug;//debug

// データを仕分けるヘルパー関数
// 小さいデータはtmpへpush、大きいデータはsrc内でrotate
static void	move_data(t_stack *src, t_stack *tmp,
		t_count *count, int pivot_data, int min_data)
{
	if (src->data[src->top] == min_data)
	{
		if (count->over > 0)// 9/23 以前（一時避難する数）
		{
			instruct_px(tmp, src);
			instruct_rx(tmp);
		}
		else
		{
			instruct_rx(src);// 9/23 検証
		}
		count->min++;
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log, ">> count->min++ [%d]\n", count->min);
	}
	else if (is_less_than(src->data[src->top], pivot_data) == true
			|| src->data[src->top] == pivot_data)
	{
		instruct_px(tmp, src);
		count->less++;
	}
	else
	{
		instruct_rx(src);
		count->over++;
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log, ">> count->over++ [%d]\n", count->over);
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

	//if (original_src_top - count.less != src->top)// 不要?
	if (count.over - 1 != src->top)
	{
		i = 0;
//		while (i < count.over)
//		{
//			instruct_rrx(src);
//			i++;
//		}
		if (src->top / 2 < count.over)
		{
			ft_dprintf(g_fd_log, ">> here?  src->top - count.over = %d\n", src->top - count.over);
			while (i < src->top + 1 - count.over)// 9/24修正　+1
			{
				instruct_rx(src);
				i++;
			}
		}
		else
		{
			if (g_flag_debug == DEBUG_ON)
				ft_dprintf(g_fd_log, ">> i [%d] < count.over [%d]\n", i, count.over);
			while (i < count.over)
			{
				if (g_flag_debug == DEBUG_ON)
					ft_dprintf(g_fd_log, ">> move large data  src->data[0] = %d\n",
						src->data[0]);
				instruct_rrx(src);
				i++;
			}
		}
	}
}

//例外処理
//　pivot_data以下の値がない時・・・分割できないため終了
//　逆順の場合・・・sort_reverseして終了
//static int	handle_exception(t_stack *src, t_stack *tmp, t_range range)
//{
//	int	pivot_data;
//
//	if (g_flag_debug == 1)// debug
//		ft_dprintf(g_fd_log, ">> call partition function\n");
//	pivot_data = src->data[range.high];
//	if (is_reverse_sorted_range(src, range.low, range.high) == true)
//	{
//		sort_reverse(src, tmp, range.high - range.low);
//		return (1);
//	}
//	//if (range.high - range.low < 7)
//	if (range.high - range.low == 2 && range.mode == MODE_NORMAL)
//	{
//		partition_three_elements(src, tmp, range);
//		//partition_small(srcs, tmp, range);
//		return (1);
//	}
//	return (0);
//}
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

void	partition(t_stack *src, t_stack *tmp, t_range range, t_count *count)
{
	int				pivot_data;
	int				min_data;
	int				min_data_less;
	int				i;
//	int				size;
	t_transition	transition;
	int				original_src_top;

	original_src_top = src->top;
//	if (handle_exception(src, tmp, range) == 1)
//		return ;
	pivot_data = get_pivot_data(src, range);
	i = 0;
	while (i < range.high - range.low + 1)
	{
		set_transition(&transition, *count, range, src, tmp);
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log,
				">> after transition low = %d  high = %d\n",
				transition.low, transition.high);
		min_data = get_min_data(src, transition.low, transition.high);
		if (count->less > 0 || count->over > 0)// 9/24 改良
		{
			if (count->less > 0)
				min_data_less = get_min_data(tmp, tmp->top - count->less + 1, tmp->top);
			else
				min_data_less = get_min_data(src, 0, count->over - 1);
			if (min_data > min_data_less)
				min_data = min_data_less;
		}
		if (g_flag_debug == DEBUG_ON)
		{
			ft_dprintf(g_fd_log,
				">> min_data = %d  src->data[top] = %d  pivot= %d\n", min_data,
				src->data[src->top], pivot_data);
			ft_dprintf(g_fd_log,
				">> is_less_than_stack ? = %d  low %d ~ high %d\n",
				is_less_than_stack_range(src,
				transition.low, transition.high, pivot_data),
				transition.low, transition.high);
		}
		// 9/23 改良　pivot_data + 1
		if (is_less_than_stack_range(src,
				transition.low, transition.high, pivot_data + 1) == false
			&& src->data[src->top] != pivot_data
			&& src->data[src->top] != min_data)
		{
			//count->over += range.high - range.low + 1 - i;// 9/23 NGかも
			break ;
		}
		move_data(src, tmp, count, pivot_data, min_data);
		i++;
	}
	move_large_data(src, *count);
	if (count->over > 0)// 9/23 修正案検証
		move_min_data(src, tmp, *count);
	count->over += range.high - range.low + 1 - i;// 9/24 move_large_dataのrra回数を合わせるため、かつrecursive_bottom_sideのrange.lowをセットするために補填
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
