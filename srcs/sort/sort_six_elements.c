/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:47:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/05 09:02:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"

static int	search_min_data(int *data, int size)
{
	int	position_min;
	int	min;
	int	i;

	i = 0;
	min = data[0];
	position_min = 0;
	while (i < size)
	{
		if (min > data[i])
		{
			min = data[i];
			position_min = i;
		}
		i++;
	}
	return (position_min);
}

static void	move_min_data(t_stack *stack_a)
{
	int	position_min;

	position_min = search_min_data(stack_a->data, stack_a->top + 1);
	if (position_min >= stack_a->top / 2)
	{
		while (position_min != stack_a->top)
		{
			instruct_rx(stack_a);
			position_min++;
		}
	}
	else
	{
		while (position_min >= 0)
		{
			instruct_rrx(stack_a);
			position_min--;
		}
	}
}

void	sort_six_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top >= 3)
	{
		move_min_data(stack_a);
		instruct_px(stack_b, stack_a);
	}
	if (is_sorted(stack_a) == false)
		sort_three_elements(stack_a);
	while (is_empty(stack_b) == false)
		instruct_px(stack_a, stack_b);
}
