/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/06 17:10:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include "debug.h"// for debug
#include "ft_printf.h"// debug
#include <stdbool.h>

//void	sort_quick(t_stack *stack_a, t_stack *stack_b, int low, int high)
void	sort_quick(t_stack *stack_a, t_stack *stack_b, t_range range)
{
	size_t	count;
	int		temp_high;
	bool	flag_sorted;
	int		partition_index;

	count = 0;
	temp_high = range.high;
	int		temp_low = range.low;//for debug
	flag_sorted = false;
	if (range.low < range.high)
	{
		ft_dprintf(fd_log, "---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				range.low, range.high, stack_a->top);
		//debug_data(stack_a, stack_b);
		while (range.high < stack_a->top)
		{
			instruct_px(stack_b, stack_a);
			count++;
		}
		ft_printf("push a -- count[%d]\n", count);
		debug_data(stack_a, stack_b);
		ft_printf(">> call partition func -- pivot=[%d]\n",
				stack_a->data[range.high]);
		partition_index = partition(stack_a, stack_b, range, &flag_sorted);
		ft_printf(">> after partition func -- pi[%d] pivot=[%d]\n",
				partition_index, stack_a->data[partition_index]);
		debug_data(stack_a, stack_b);
		range.high = partition_index - 1;
		//sort_quick(stack_a, stack_b, low, pi - 1);
		ft_printf(">> call recursive sort_quick func -- bottom side\n");
		sort_quick(stack_a, stack_b, range);
		ft_printf("this???\n");
		if (flag_sorted == false)
		{
			range.low = partition_index + 1;
			range.high = temp_high;
			//sort_quick(stack_a, stack_b, pi + 1, high);
			ft_printf(">> call recursive sort_quick func -- top side\n");
			sort_quick(stack_a, stack_b, range);
		}
		ft_printf("this???\n");
		while (count > 0)
		{
			instruct_px(stack_a, stack_b);
			count--;
		}
		ft_printf("---- end time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				temp_low, temp_high, stack_a->top);
	}
}
