/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/06 15:48:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include "debug.h"// for debug
#include "ft_printf.h"// debug
#include <stdbool.h>

int	partition(t_stack *stack_a, t_stack *stack_b, t_range range, bool *flag_sorted)
{
	int	pivot_data;
	int	size;
	int	i;
	int	count_over;
	int	count_less;

	pivot_data = stack_a->data[range.high];
	size = range.high - range.low;
	//ft_printf("pivot_data[%d] size[%d]=high[%d]-low[%d] top[%d]\n",
	//		pivot_data, size, range.high, range.low, stack_a->top);
	while (range.high < stack_a->top)
		instruct_px(stack_b, stack_a);
	i = 0;
	instruct_rx(stack_a);
	count_over = 0;
	count_less = 0;
	while (i < size)
	{
		if (stack_a->data[stack_a->top] < pivot_data)
		{
			instruct_px(stack_b, stack_a);
			count_less++;
		}
		else
		{
			instruct_rx(stack_a);
			count_over++;
			//ft_printf("count_over++ -> [%d]\n", count_over);
		}
		i++;
	}
	if (range.low > 0)
	{
		i = 0;
		//ft_printf("i[%d] < count_over[%d]\n", i, count_over);
		while (i < count_over + 1)
		{
			instruct_rrx(stack_a);
			i++;
		}
	}
	i = stack_a->top;
	//debug_data(stack_a, stack_b);
	while (count_less-- > 0)
		instruct_px(stack_a, stack_b);
	if (is_sorted(stack_a) == true)
		*flag_sorted = true;
	//debug_data(stack_a, stack_b);
	//ft_printf("flag [%d], true[%d] false[%d]\n", *flag_sorted, true, false);
//	while (is_empty(stack_b) == false)
//		instruct_px(stack_a, stack_b);
	return (i);
}
