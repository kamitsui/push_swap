/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 16:17:00 by kamitsui         ###   ########.fr       */
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
// 小さいデータはsrc内でrotate、大きいデータはtmpへpush
static void	move_data(t_stack *src, t_stack *tmp,
		t_count *count, int pivot_data, int min_data)
{
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log,
//			">>in move_data min_data = %d  src->data[top] = %d\n", min_data,
//			src->data[src->top]);
	if (src->data[src->top] == min_data)
	{
		instruct_px(tmp, src);
		instruct_rx(tmp);
		count->min++;
	}
	else if (is_less_than(src->data[src->top], pivot_data) == true
			|| src->data[src->top] == pivot_data)
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
//		if (g_flag_debug == 1)// debug
//			ft_dprintf(g_fd_log, "count->less++ -> [%d]\n", count->less);
//		if (g_flag_debug == 1)// debug
//			ft_dprintf(g_fd_log, "count->over++ -> [%d]\n", count->over);

//例外処理
//　pivot_data以上の値がない時・・・分割できないため終了
//　逆順の場合・・・sort_reverseして終了
//　pivot_dataが一番小さい時、rotateして終了（top側の分割）
//static int	handle_exception(t_stack *src, t_stack *tmp, t_range range)
//{
//	int	pivot_data;
//
//	if (g_flag_debug == 1)// debug
//		ft_dprintf(g_fd_log, ">> call partition_reverse function\n");
//	pivot_data = src->data[range.high];
//	if (is_sorted_range(src, range.low, range.high) == true)
//	{
//		sort_reverse(src, tmp, range.high - range.low);
//		return (1);
//	}
//	if (range.high - range.low == 2 && range.mode == MODE_REVERSE)
//	{
//		partition_three_elements(src, tmp, range);
//		//partition_small(srcs, tmp, range);
//		return (1);
//	}
//	return (0);
//}
//debug code
//partition関数に入った時の状態＋is_more_than...関数の結果
//	if (g_flag_debug == 1)// debug
//		ft_dprintf(g_fd_log, ">> call partition_reverse function\n");
//sort_reverse関数を呼ぶ前のデバッグ
//		if (g_flag_debug == 1)// for debug
//			ft_dprintf(g_fd_log, ">> call sort_reverse func -- size[%d]\n",
//					range.high - range.low);
//sort_reverse関数の後のスタックをデバッグ
//		if (g_flag_debug == 1)// for debug
//			debug_data(g_fd_log, src, tmp);

//static void	move_large_data(t_stack *src, t_stack *tmp, t_count count)
//static void	move_large_data(t_stack *src, t_count count)
//{
//	int	i;
//
//	i = 0;
//	while (i++ < count.less)
//		instruct_rrx(src);
////	instruct_rrx(tmp);
//}

void	partition_reverse(t_stack *src, t_stack *tmp, t_range range, t_count *count)
{
	int				pivot_data;
	int				min_data;
	int				min_data_less;
	int				i;
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
		min_data = get_min_data(src, transition.low, transition.high);
		if (count->less > 0 || count->over > 0)// 9/24 改良
		{
			if (count->less > 0)
				min_data_less = get_min_data(src, 0, transition.low - 1);
			else
				min_data_less = get_min_data(tmp, tmp->top + 1 - count->over, tmp->top);
			if (min_data > min_data_less)
				min_data = min_data_less;
		}
//		if (count->less > 0)
//		{
//			min_data_tmp = get_min_data(src, 0, transition.low - 1);
//			if (min_data > min_data_tmp)
//				min_data = min_data_tmp;
//		}
//		if (g_flag_debug == DEBUG_ON)
//			ft_dprintf(g_fd_log,
//				">> min_data = %d  src->data[top] = %d  pivot= %d\n", min_data,
//				src->data[src->top], pivot_data);
		//if (is_more_than_stack_range(src,
		if (is_more_than_stack_range(src,
				transition.low, transition.high, pivot_data) == false)
			break ;
		move_data(src, tmp, count, pivot_data, min_data);
		i++;
	}
// いらないのでは？？ 9/22
//	if (original_src_top - count.over != src->top)
//		move_large_data(src, count);
}
//デバッグ用のフラグ
//	g_flag_debug = 1;
//breakするか否か？
//		if (g_flag_debug == 1)// debug
//		{
//			ft_dprintf(g_fd_log, ">> transition.low[%d] transition.high[%d]\n",
//				transition.low, transition.high);
//			ft_dprintf(g_fd_log,
//				">> data_low[%d] ~ data_high[%d] ... pivot_data[%d]\n",
//				src->data[transition.low],
//				src->data[transition.high], pivot_data);
//			ft_dprintf(g_fd_log,
//				">> is_more_than_stack_range = [%d] false[%d] true[%d]\n",
//				is_more_than_stack_range(src, transition.low,
//				transition.high, pivot_data),
//				false, true);
//			ft_dprintf(g_fd_log,
//				">> check include data more than pivot_data\n");
//		}
//break 時のメッセージ出力
//			if (g_flag_debug == 1)
//				ft_dprintf(g_fd_log, "break\n");
//move_data関数の対象データとpivot_dataを比較する
//		if (g_flag_debug == 1)// debug
//		{
//			ft_dprintf(g_fd_log,
//				">> is_more_than( %d , %d ) = [%d] false[%d] true[%d]\n",
//				src->data[src->top], pivot_data,
//				is_more_than(src->data[src->top], pivot_data), false, true);
//		}
//		ft_dprintf(g_fd_log, ">> call move_data_reverse\n");
