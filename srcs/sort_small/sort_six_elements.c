/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:47:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:59:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort_six_elements.c
 * @brief This sort function is used when the number of elements
 * is less than or equal to six.
 */
#include "push_swap.h"
#include "instruct.h"
#include "sort.h"

/**
 * @brief Search the position of the minimum value in an array
 *
 * @param data is an array
 * @param size is the number of array elements
 *
 * @return 
 */
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

/**
 * @brief Move the minimum data to the top of the stack.
 *
 * @param stack
 */
static void	move_min_data_to_top(t_stack *stack)
{
	int	position_min;

	position_min = search_min_data(stack->data, stack->top + 1);
	if (position_min >= stack->top / 2)
	{
		while (position_min != stack->top)
		{
			instruct_rx(stack);
			position_min++;
		}
	}
	else
	{
		while (position_min >= 0)
		{
			instruct_rrx(stack);
			position_min--;
		}
	}
}

/**
 * @brief This sort function is used when the number of elements
 * is less than or equal to six.
 *
 * @param src is unsorted.
 * @param tmp is working stack
 */
void	sort_six_elements(t_stack *src, t_stack *tmp)
{
	while (src->top >= 3)
	{
		move_min_data_to_top(src);
		instruct_px(tmp, src);
	}
	if (is_sorted(src) == false)
		sort_three_elements(src);
	while (is_empty(tmp) == false)
		instruct_px(src, tmp);
}
