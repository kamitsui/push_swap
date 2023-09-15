/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 11:04:43 by kamitsui         ###   ########.fr       */
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

static void	move_data_normal_mode(t_stack *src, t_stack *tmp,
		t_count *count, int pivot_data)
{
	// 小さい値：tmp へ避難させる px(tmp, src)
	if (is_less_than(src->data[src->top], pivot_data) == true)
	{
		instruct_px(tmp, src);
		count->less++;
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, "count->less++  [%d]\n", count->less);
	}
	// 大きい値：src 内でrotateする。
	else
	{
		instruct_rx(src);
		count->over++;
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, "count->over++  [%d]\n", count->over);
	}
}

void	reverse_rotate_large_data(t_stack *src, t_count count)
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

void	partition(t_stack *src, t_stack *tmp, t_range range)
{
	int	pivot_data;
	int	size;
	int	i;
	t_count	count;
	flag_debug = 1;

	pivot_data = src->data[range.high];
	size = range.high - range.low;

	// is_less_than_stack_range   pivot_dataより小さい数値があるか？
	if (flag_debug == 1)// debug
	{
		ft_dprintf(fd_log, ">> call partition function\n");
		ft_dprintf(fd_log,
			">> is_less_than_stack_range = [%d] false[%d] true[%d]\n",
			is_less_than_stack_range(src, range.low, range.high - 1, pivot_data),
			false, true);
	}

	// partition 終了条件：pivod_dataが一番小さい値の場合
	if (is_less_than_stack_range(src, range.low, range.high - 1, pivot_data) == false)
	{
		if (flag_debug == 1)//debug
			ft_dprintf(fd_log,
				">> stop partition ... pivot data is most small data\n");
		//instruct_px(tmp, src);
		return ;
	}

	// range内のデータが逆順だったら、逆sortをさせる。手数を減らす手法
	if (is_reverse_sorted_range(src, range.low, range.high) == true)
	{
		if (flag_debug == 1)// for debug
			ft_dprintf(fd_log, ">> call sort_reverse func -- size[%d]\n",
					range.high - range.low);
		sort_reverse(src, tmp, range.high - range.low);
		//instruct_px(tmp, src);
		if (flag_debug == 1)// for debug
			debug_data(fd_log, src, tmp);
		return ;
	}

	// ここからが通常の処理
	// pivot_dataを逃す ra
	instruct_rx(src);
	int	offset;
	int	transition_low;
	int	transition_high;

// 仕分ける作業：大きい値は　src内に留めて、　小さい値は tmp に避難する
	count.over = 0;
	count.less = 0;
	offset = range.low + 1;//pivot_dataをraさせたため、offsetを足す
	i = 0;
	while (i < size)
	{
		transition_low = offset + count.over;
		transition_high = range.high - count.less + count.over;
		//transition_high = src->top???;
		if (flag_debug == 1)// debug  breakするか否か？の状態確認
		{
			ft_dprintf(fd_log, ">> low[%d] ~ high[%d] ... pivot_data[%d]\n",
				src->data[offset + count.less],
				src->data[range.high - count.less + count.over], pivot_data);
			ft_dprintf(fd_log, ">> is_less_than_stack_range = [%d] false[%d] true[%d]\n",
				is_less_than_stack_range(src, offset + count.over,
				range.high - count.less + count.over, pivot_data),
				true, false);
		}

		// ループ終了条件　pivot_data以上の値しかない場合
		// breakして、無駄なraをなくす。
		if (is_less_than_stack_range(src,
				transition_low, transition_high, pivot_data) == false)
		{
			if (flag_debug == 1)//debug
				ft_dprintf(fd_log, "break\n");
			break ;
		}

		if (flag_debug == 1)// debug
		{
			ft_dprintf(fd_log,
				">> is_less_than( %d , %d ) = [%d] true[%d] false[%d]\n",
				src->data[src->top], pivot_data,
				is_less_than(src->data[src->top], pivot_data), true, false);
		}
		move_data_normal_mode(src, tmp, &count, pivot_data);
		i++;
	}

	// 大きい値を元に戻す作業 (stack_a のTOPに戻す）
	reverse_rotate_large_data(src, count);
}
