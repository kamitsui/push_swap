/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:07:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 20:29:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

// for debug
#include "debug.h"

// Function to find the median value from an array of integers
//static int	get_min_data_range(t_stack *stack, int low, int high)
static int	get_min_data_range(t_stack *stack, int low, int high)
{
	int	size;
	int	arr_stack[MAX_SIZE];
	int	*arr;
	int	min;

	size = high - low + 1;
	if (size > MAX_SIZE)
		arr = allocate_array(size);
	else
		arr = &arr_stack[0];
	ft_memcpy(arr, &stack->data[low], size * sizeof(int));
	ft_qsort(arr, 0, size - 1);
	min = arr[0];
	if (size > MAX_SIZE)
		free(arr);
	return (min);
}
//debug code
//	debug_array(arr, size);

static int	get_min_data_from_moved_data(t_stack *src, t_stack *tmp,
		t_range range, t_count count)
{
	int	min_data;

	if (range.mode == TOP_SIDE)
	{
		if (count.less > 0)
			min_data = get_min_data_range(src, 0, range.transition_low - 1);
		else
			min_data = get_min_data_range(
					tmp, tmp->top + 1 - count.over, tmp->top);
	}
	else
	{
		if (count.less > 0)
			min_data = get_min_data_range(
					tmp, tmp->top - count.less + 1, tmp->top);
		else
			min_data = get_min_data_range(src, 0, count.over - 1);
	}
	return (min_data);
}

int	get_min_data(t_stack *src, t_stack *tmp, t_range range, t_count count)
{
	int	min_data;
	int	min_data_moved;

	min_data = get_min_data_range(
			src, range.transition_low, range.transition_high);
	if (count.less > 0 || count.over > 0)
	{
		min_data_moved = get_min_data_from_moved_data(src, tmp, range, count);
		if (min_data > min_data_moved)
			min_data = min_data_moved;
	}
	return (min_data);
}
