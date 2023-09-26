/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:08:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:54:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// for debug
#include "debug.h"

static int	get_median(int arr[], int size)
{
	long	mid1;
	long	mid2;
	int		median;

	if (size % 2 == 0)
	{
		mid1 = arr[(size - 1) / 2];
		mid2 = arr[size / 2];
		median = (int)((mid1 + mid2) / 2);
	}
	else
	{
		median = arr[size / 2];
	}
	return (median);
}
// debug code
//		debug_median_even(mid1, mid2, median);
//		debug_median_odd(median);

// Function to find the median value from an array of integers
int	get_pivot_data(t_stack *stack, t_range range)
{
	int	size;
	int	arr_stack[MAX_SIZE];
	int	*arr;
	int	pivot_data;

	size = range.high - range.low + 1;
	if (size > MAX_SIZE)
		arr = allocate_array(size);
	else
		arr = &arr_stack[0];
	ft_memcpy(arr, &stack->data[range.low], size * sizeof(int));
	ft_qsort(arr, 0, size - 1);
	pivot_data = get_median(arr, size);
	if (size > MAX_SIZE)
		free(arr);
	return (pivot_data);
}
//debug code
//	debug_get_pivot_data_start(range, size);
//	debug_array_before(arr, size);
//	debug_array_after(arr, size);
