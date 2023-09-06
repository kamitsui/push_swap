/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/06 14:58:14 by kamitsui         ###   ########.fr       */
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
	flag_sorted = false;
	if (range.low < range.high)
	{
		while (range.high < stack_a->top)
		{
			instruct_px(stack_a, stack_b);
			count++;
		}
		partition_index = partition(stack_a, stack_b, range, &flag_sorted);
		range.high = partition_index - 1;
		//sort_quick(stack_a, stack_b, low, pi - 1);
		sort_quick(stack_a, stack_b, range);
		ft_printf("this???\n");
		if (flag_sorted == false)
		{
			range.low = partition_index + 1;
			range.high = temp_high;
			//sort_quick(stack_a, stack_b, pi + 1, high);
			sort_quick(stack_a, stack_b, range);
		}
		while (count > 0)
		{
			instruct_px(stack_a, stack_b);
			count--;
		}
	}
}
