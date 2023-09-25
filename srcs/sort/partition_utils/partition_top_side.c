/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_top_side.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 21:08:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

//デバッグ用
#include "debug.h"// for debug
#include "ft_printf.h"// debug

void	partition_top_side(t_stack *src, t_stack *tmp,
		t_range range, t_count *count)
{
	int				min_data_less;
	int				i;
//	t_transition	transition;

	debug_partition_start(range.mode);
	range.pivot_data = get_pivot_data(src, range);
	i = 0;
	while (i < range.high - range.low + 1)
	{
		set_transition(src, tmp, *count, &range);
		//set_transition(&transition, *count, range, src, tmp);
//		range.min_data = get_min_data(src, tmp, transition, *count);
		range.min_data = get_min_data(src, range.transition_low, range.transition_high);
		if (count->less > 0 || count->over > 0)
		{
			if (count->less > 0)
				min_data_less = get_min_data(src, 0, range.transition_low - 1);
			else
				min_data_less = get_min_data(tmp, tmp->top + 1 - count->over, tmp->top);
			if (range.min_data > min_data_less)
				range.min_data = min_data_less;
		}
//		if (count->less > 0)
//		{
//			min_data_tmp = get_min_data(src, 0, transition.low - 1);
//			if (min_data > min_data_tmp)
//				min_data = min_data_tmp;
//		}
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log,
				">> min_data = %d  src->data[top] = %d  pivot= %d\n",
				range.min_data, src->data[src->top], range.pivot_data);
		if (is_more_than_stack_range(src,
				range.transition_low, range.transition_high, range.pivot_data) == false
			&& src->data[src->top] != range.pivot_data
			&& src->data[src->top] != range.min_data)
			break ;
		move_data(src, tmp, count, range);
		i++;
	}
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
