/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/05 19:26:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "debug.h"// for debug
#include "ft_printf.h"// debug

int	partition(t_stack *stack_a, t_stack *stack_b, int low, int high)
{
	int	pivot;
	int	size;
	int	i;

	pivot = stack_a->data[high];
	size = high - low + 1;
	ft_printf("pivot[%d] size[%d] high[%d] top[%d]\n",
			pivot, size, high, stack_a->top);
	while (high < stack_a->top)
		instruct_px(stack_b, stack_a);
	i = 0;
	instruct_rx(stack_a);
	while (i < size - 1)
	{
		if (stack_a->data[stack_a->top] > pivot)
			instruct_px(stack_b, stack_a);
		else
			instruct_rx(stack_a);
		i++;
	}
	i = stack_a->top;
	//debug_data(stack_a, stack_b);
	while (is_empty(stack_b) == false)
		instruct_px(stack_a, stack_b);
	return (i);
}

void	sort_quick(t_stack *stack_a, t_stack *stack_b, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(stack_a, stack_b, low, high);
		sort_quick(stack_a, stack_b, low, pi - 1);
		sort_quick(stack_a, stack_b, pi + 1, high);
	}
}
