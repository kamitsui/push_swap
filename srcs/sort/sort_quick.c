/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 21:24:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

// for debug
//#include "debug.h"
//#include "ft_printf.h"
//
//int	g_fd_log;
//int	g_flag_debug;

// debug function
//static void	debug_after_recursive_top_side(
//		t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log,
//			"---- end recursive_top_side ---- \
//\x9	\x9	\x9	range low[%d] ~ high[%d] ... \
//\x9	\x9	\x9	src->top[%d] tmp->top[%d] mode[%d]\n",
//			range.low, range.high, src->top, tmp->top, range.mode);
//	}
//}

// debug function
//static void	debug_after_recursive_bottom_side(
//		t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log,
//			"---- end recursive_bottom_side ---- \
//\x9	\x9	\x9	range low[%d] ~ high[%d] ... \
//\x9	\x9	\x9	src->top[%d] tmp->top[%d] mode[%d]\n",
//			range.low, range.high, src->top, tmp->top, range.mode);
//	}
//}

// debug function
//static void	debug_after_partition(t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, ">> after partition func\n");
//		debug_data(g_fd_log, src, tmp);
//		debug_range(range);
//	}
//}

/**
 * @brief クイックソート（再帰関数）
 *
 * @param src ソート対象のスタック
 * @param tmp ソートの際に避難させるスタック
 * @param range ソート範囲（srcスタックの要素番号）
 */
//void	sort_quick(t_stack *src, t_stack *tmp, t_range range)
void	sort_quick(t_stack *src, t_stack *tmp, t_range range, t_count count)
{
	//t_count	count;// rangeに含めるか 再帰の引数に含めるか　要検討
	int		i;

//	count.over = 0;
//	count.less = 0;
//	count.min = 0;
	if (range.low < range.high
		|| is_sorted_range(src, range.low, range.high) == false)
	{
//		debug_sort_quick_start(src, tmp, range);
		if (range.mode == 0)
			partition(src, tmp, range, &count);
		else
			partition_reverse(src, tmp, range, &count);
//		debug_after_partition(src, tmp, range);
		recursive_top_side(src, tmp, range, count);
//		debug_after_recursive_top_side(src, tmp, range);
		//recursive_bottom_side(src, tmp, range, count);
		recursive_bottom_side(src, tmp, range, count);
//		debug_after_recursive_bottom_side(src, tmp, range);
	}
	else if (range.mode == MODE_NORMAL)
	{
		i = 0;
		while (i++ < range.high + 1 - range.low)
			instruct_rx(src);
	}
	end_process(src, tmp, range);
//	debug_sort_quick_end(src, tmp, range);
}

//この関数で使う debug functions
//sort_quick関数の開始状況をデバッグ　（１回分のソート開始状況がわかる）
//	debug_sort_quick_start(src, tmp, range);
//partition関数で分割された後の状態をデバッグ
//	debug_after_partition(src, tmp, range);
//top側の再帰ソートが終わった後の状態をデバッグ
//	debug_after_recursive_top_side(src, tmp, range);
//bottom側の再帰ソートが終わった後の状態をデバッグ
//	debug_after_recursive_bottom_side(src, tmp, range);
//sort_quick関数の
//	debug_sort_quick_end(src, tmp, range);
