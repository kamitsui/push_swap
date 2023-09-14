/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/14 21:36:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include "debug.h"// for debug
#include "ft_printf.h"// debug
#include <stdbool.h>

int	fd_log;// for debug
int	flag_debug;//debug

static void	move_data_reverse_mode(t_stack *src, t_stack *tmp,
		t_count *count, int pivot_data)
{
	// 小さい値：src 内でrotateする。
	ft_dprintf(fd_log, "data[%d] pivot_data[%d]\n", src->data[src->top], pivot_data);
	if (is_less_than(src->data[src->top], pivot_data) == true)
	{
		instruct_rx(src);
		count->less++;
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, "count->less++ -> [%d]\n", count->less);
	}
	// 大きい値：tmp へ避難させる push tmp
	else
	{
		instruct_px(tmp, src);
		count->over++;
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, "count->over++ -> [%d]\n", count->over);
	}
}

void	partition_reverse(t_stack *src, t_stack *tmp, t_range range)
{
	int	pivot_data;
	int	size;
	int	i;
	t_count	count;
	flag_debug = 1;

	pivot_data = src->data[range.high];
	size = range.high - range.low;

	// is_more_than_stack_range   pivot_dataより大きい数値があるか？
	if (flag_debug == 1)// debug
	{
		ft_dprintf(fd_log, ">> call partition_reverse function\n");
		ft_dprintf(fd_log,
			">> is_more_than_stack_range = [%d] false[%d] true[%d]\n",
			is_more_than_stack_range(src, range.low, range.high, pivot_data),
			false, true);
	}

	// partition 終了条件：pivot_dataが一番大きい値の場合
	if (is_more_than_stack_range(src, range.low, range.high, pivot_data) == false)
	{
		if (flag_debug == 1)//debug
			ft_dprintf(fd_log,
				">> stop partition_reverse ... pivot_data is most large data\n");
		instruct_px(tmp, src);
		return ;
	}

	// range内のデータが逆順だったら、逆sortをさせる。
	// この条件だめかも？？　bottom側のデータも見てしまっているため? 保留
	if (is_sorted_range(src, range.low, range.high) == true)
	{
		if (flag_debug == 1)// for debug
			ft_dprintf(fd_log, ">> call sort_reverse func -- size[%d]\n",
					range.high - range.low);
		sort_reverse(src, tmp, range.high - range.low);
		if (flag_debug == 1)// for debug
			debug_data(fd_log, src, tmp);
	}

	// ここからが通常の処理
	// pivot_dataを逃す push src->tmp + rotate src
	instruct_px(tmp, src);
	instruct_rx(tmp);
	int offset;
	int	transition_low;
	int	transition_high;

	debug_data(fd_log, src, tmp);

// 仕分ける作業：大きい値は　tmpへpushし、　小さい値は src内 に留める
	count.over = 0;//pivot_dataをpushさせたため、count.overを足す
	count.less = 0;
	offset = 0;
	i = 0;
	while (i < size)
	{
		transition_low = offset + count.over;
		transition_high = range.high - count.less + count.over;
		if (flag_debug == 1)// debug  breakするか否か？の状態確認
		{
			ft_dprintf(fd_log, ">> transition_low[%d] transition_high[%d]\n",
					transition_low, transition_high);
			ft_dprintf(fd_log, ">> data_low[%d] ~ data_high[%d] ... pivot_data[%d]\n",
				src->data[transition_low],
				src->data[transition_high], pivot_data);
			ft_dprintf(fd_log, ">> is_less_than_stack_range = [%d] false[%d] true[%d]\n",
				is_less_than_stack_range(src, transition_low,
				transition_high, pivot_data),
				false, true);
		}

		// ループ終了条件　pivot_data以下の値しかない場合
		// breakして、無駄なraをなくす。
		if (is_less_than_stack_range(src,
				transition_low, transition_high, pivot_data)
					== false)
		{
			if (flag_debug == 1)
				ft_dprintf(fd_log, "break\n");
			break ;
		}

		if (flag_debug == 1)// debug
		{
			ft_dprintf(fd_log,
				">> is_more_than( %d , %d ) = [%d] false[%d] true[%d]\n",
				src->data[src->top], pivot_data,
				is_more_than(src->data[src->top], pivot_data), false, true);
		}
		ft_dprintf(fd_log, ">> call move_data_reverse\n");
		move_data_reverse_mode(src, tmp, &count, pivot_data);
		i++;
	}
	i = 0;
	while (i++ < count.less)
		instruct_rrx(src);
	instruct_rrx(tmp);
}
