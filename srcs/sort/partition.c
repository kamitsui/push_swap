/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/13 16:24:50 by kamitsui         ###   ########.fr       */
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

void	partition(t_stack *src, t_stack *tmp, t_range *range)
{
	int	pivot_data;
	int	size;
	int	i;
	int	count_over;
	int	count_less;
	flag_debug = 1;

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log, ">> call partition\n");
		debug_data(fd_log, src, tmp);
	}

	pivot_data = src->data[range->high];
	size = range->high - range->low;

	// is_less_than_stack_range   pivot_dataより小さい数値があるか？
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log,
			">> is_less_than_stack_range = [%d] true[%d] false[%d]\n",
			is_less_than_stack_range(src, range->low, range->high, pivot_data),
			true, false);

	// range内のデータが逆順だったら、逆sortをさせる。手数を減らす手法
	if (is_reverse_sorted_range(src, range->low, range->high) == true)
	{
		if (flag_debug == 1)// for debug
			ft_dprintf(fd_log, ">> call sort_reverse func -- size[%d]\n",
					range->high - range->low);
		sort_reverse(src, tmp, range->high - range->low);
		if (flag_debug == 1)// for debug
			debug_data(fd_log, src, tmp);
		//return (range->low);
	}

	// ここからが通常の処理
	// pivot_dataを逃す ra
	instruct_rx(src);
	int	offset;
	offset = range->low + 1;//pivot_dataをraさせたため、offsetを足す

// 仕分ける作業：大きい値は　src内に留めて、　小さい値は tmp に避難する
	count_over = 0;
	count_less = 0;
	i = 0;
	while (i < size)
	{
		if (flag_debug == 1)// debug  breakするか否か？の状態確認
		{
			ft_dprintf(fd_log, ">> low[%d] ~ high[%d] ... pivot_data[%d]\n",
				src->data[offset + count_less],
				src->data[range->high - count_less + count_over], pivot_data);
			ft_dprintf(fd_log, ">> is_less_than_stack_range = [%d] true[%d] false[%d]\n",
				is_less_than_stack_range(src, offset + count_over,
				range->high - count_less + count_over, pivot_data),
				true, false);
		}

		// breakして、無駄なraをなくす。
		if (is_less_than_stack_range(src,
				offset + count_over, range->high - count_less + count_over,
				pivot_data) == false)
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

		// 小さい値：tmp へ避難させる px(tmp, src)
		if (is_less_than(src->data[src->top], pivot_data) == true)
		{
			instruct_px(tmp, src);
			count_less++;
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, "count_less++ -> [%d]\n", count_less);
		}

		// 大きい値：src 内でrotateする。
		else
		{
			instruct_rx(src);
			count_over++;
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, "count_over++ -> [%d]\n", count_over);
		}
		i++;
	}

	// 大きい値を元に戻す作業
	if (count_over != src->top)
	{
		if (flag_debug == 1)// for debug
			debug_data(fd_log, src, tmp);
		i = 0;
		while (i < count_over + 1)
		{
			instruct_rrx(src);
			i++;
		}
	}
// -------------- bottom side と top side 整理完了 --------------
// この時点がtmp->topがrange->highになる。
// 次はこのrangeがsortの対象（top side）
	range->high = tmp->top;
// ----------------------------------------------------------------
}
