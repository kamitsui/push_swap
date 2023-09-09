/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/09 21:00:28 by kamitsui         ###   ########.fr       */
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

int	partition(t_stack *stack_a, t_stack *stack_b, t_range range)
{
	int	pivot_data;
	int	size;
	int	i;
	int	count_over;
	int	count_less;
	flag_debug = 1;

	pivot_data = stack_a->data[range.high];
	size = range.high - range.low;
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "pivot_data[%d] size[%d]=high[%d]-low[%d] top[%d]\n",
			pivot_data, size, range.high, range.low, stack_a->top);
	while (range.high < stack_a->top)
		instruct_px(stack_b, stack_a);
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "[%d]pivot_data\n", pivot_data);
	i = 0;
	// is_less_than_in_stack_range
	// ピボットの値未満しかなければ、以下の処理をせず、range.highを返す
	// 期待効果は、無駄な命令が減る。
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "[%d] is_less_than_range_stack(..., pivot_data[%d])\n",
			is_less_than_range_stack(stack_a, range.low, range.high, pivot_data), pivot_data);
		// ここがおかしい　run5.sh で発覚 pivotより大きい値があるのに、
	if (is_less_than_range_stack(stack_a, range.low, range.high, pivot_data) == false)
		return (range.high);
//	ft_dprintf(fd_log, "before is_reverse_sorted_range\n");//debug
//	if (flag_debug == 1)// for debug
//		ft_dprintf(fd_log, "is_reverse_sorted_range? [%d]\n",
//			is_reverse_sorted_range(stack_a, range.low, range.high));

	// この条件だめかも？？　bottom側のデータも見てしまっているため? 保留
	if (is_reverse_sorted_range(stack_a, range.low, range.high) == true)
	{
		if (flag_debug == 1)// for debug
			ft_dprintf(fd_log, ">> call sort_reverse func -- size[%d]\n",
					range.high - range.low);
		sort_reverse(stack_a, stack_b, range.high - range.low);
		if (flag_debug == 1)// for debug
			debug_data(fd_log, stack_a, stack_b);
		ft_dprintf(fd_log, "flag_sorted pointer [%p]\n", range.flag_sorted);
		*(range.flag_sorted) = true;
		return (range.low);
	}
	instruct_rx(stack_a);
	range.low++;//maybe ?
	count_over = 0;
	count_less = 0;
	while (i < size)
	{
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, "[%d] is_less_than_range_stack(..., low[%d], high[%d], pivot_data[%d])\n",
			is_less_than_range_stack(stack_a, range.low + count_over, range.high - count_less + count_over, pivot_data), stack_a->data[range.low + count_less], stack_a->data[range.high - count_less + count_over], pivot_data);
		//if (is_less_than_range_stack(stack_a, range.low + count_over, range.high - count_less + count_over, pivot_data) == false)
		if (is_less_than_range_stack(stack_a, range.low + count_over, range.high - count_less + count_over, pivot_data) == false)
		{
			if (flag_debug == 1)
				ft_dprintf(fd_log, "break\n");
			break ;
		}
		if (flag_debug == 1)
			ft_dprintf(fd_log, ">> if ( %d < %d\n", stack_a->data[stack_a->top], pivot_data);
		if (stack_a->data[stack_a->top] < pivot_data)
		{
			instruct_px(stack_b, stack_a);
			count_less++;
			if (flag_debug == 1)
				ft_dprintf(fd_log, "count_less++ -> [%d]\n", count_less);
		}
		else
		{
			if (flag_debug == 1)
				ft_dprintf(fd_log, ">> call ra\n");
			instruct_rx(stack_a);
			count_over++;
			if (flag_debug == 1)
				ft_dprintf(fd_log, "count_over++ -> [%d]\n", count_over);
		}
		i++;
	}
	//if (range.low > 0)
	if (count_over != stack_a->top)
	{
		if (flag_debug == 1)// for debug
			debug_data(fd_log, stack_a, stack_b);
		i = 0;
		while (i < count_over + 1)
		{
			instruct_rrx(stack_a);
			i++;
		}
	}
	i = stack_a->top;
	if (flag_debug == 1)//debug
		debug_data(fd_log, stack_a, stack_b);
	// スタックBがis_sort なら、is_reverse_sortなら  未確認
	if (is_sorted(stack_b) == true)
	{
		while (count_less > 0)
		{
			if (count_less > 1)
				instruct_rrx(stack_b);
			instruct_px(stack_a, stack_b);
			count_less--;
			//range.flag_sorted = true;
		}
	}
	else
		while (count_less-- > 0)
			instruct_px(stack_a, stack_b);
	if (is_sorted(stack_a) == true)
		*(range.flag_sorted) = true;
	else
		*(range.flag_sorted) = false;
	if (flag_debug == 1)
	debug_data(fd_log, stack_a, stack_b);
	if (flag_debug == 1)
		ft_dprintf(fd_log, "flag [%d], true[%d] false[%d]\n", *(range.flag_sorted), true, false);
	return (i);
}
