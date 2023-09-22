/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:07:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/22 13:26:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "debug.h"

// Function to find the median value from an array of integers
int	get_min_data(t_stack *stack, t_range range)
{
	int	size;
	int	arr_stack[MAX_SIZE];
	int	*arr;

	size = range.high - range.low + 1;
	if (size > MAX_SIZE)
		arr = allocate_array(size);
	else
		arr = &arr_stack[0];
	ft_memcpy(arr, &stack->data[range.low], size * sizeof(int));
	ft_qsort(arr, 0, size - 1);
	debug_array(arr, size - 1);
	return (arr[0]);
}
