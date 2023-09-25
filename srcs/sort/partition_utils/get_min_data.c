/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:07:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 20:43:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "debug.h"
#include <stdlib.h>

// Function to find the median value from an array of integers
//static int	get_min_data_range(t_stack *stack, int low, int high)
int	get_min_data(t_stack *stack, int low, int high)
{
	int	size;
//	int	arr_stack[MAX_SIZE];
	int	*arr;
	int	min;

	size = high - low + 1;
//	if (size > MAX_SIZE)
		arr = allocate_array(size);
//	else
//		arr = &arr_stack[0];
	ft_memcpy(arr, &stack->data[low], size * sizeof(int));
	ft_qsort(arr, 0, size - 1);
	min = arr[0];
	free(arr);
	return (min);
}
//debug code
//	debug_array(arr, size);

//static int	get_min_data_from_moved_data(t_stack *src, t_stack *tmp,
//		t_transition transition, t_count count)
//{
//	int	min_data;
//
//	if (count.less > 0)
//		min_data_less = get_min_data_range(tmp,
//			tmp->top - count.less + 1, tmp->top);
//	else
//		min_data_less = get_min_data_range(src, 0, count.over - 1);
//	return (min_data);
//}
//
//int	get_min_data(t_stack *stack, t_stack tmp,
//		t_transition transition, t_count count)
//{
//	int	min_data;
//	int	min_data_less;
//
//	min_data = get_min_data_range(src, transition.low, transition.high);
//	if (count.less > 0 || count.over > 0)
//	{
//		min_data_less = get_min_data_from_moved_data(src, tmp, transition, count);
//		if (range.min_data > min_data_less)
//			min_data = min_data_less;
//	}
//	return (min_data);
//}
