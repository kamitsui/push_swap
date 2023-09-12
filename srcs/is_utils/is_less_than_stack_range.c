/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_less_than_stack_range.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 07:19:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/12 16:23:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_less_than_in_stack.c
 * @brief Check if a is less than b
 */
#include "push_swap.h"
#include <stdbool.h>
#include "ft_printf.h"

int	fd_log;//debug

/**
 * @brief Check if the array's data in the range on stack is less than value
 *
 * @param a is the smaller integer to compare
 * @param b is the larger integer to compare
 *
 * @return true: a < b  false: other
 */
bool	is_less_than_stack_range(t_stack *stack,
		int low, int high, int pivot_data)
{
	int		size;
	int		i;
	bool	result;

	size = high - low + 1;
	i = 0;
	result = false;
	while (i < size)
	{
		if (stack->data[high - i] < pivot_data)
		{
			result = true;
			break ;
		}
		i++;
	}
	ft_dprintf(fd_log, "---- is_less_than -> [%d] %d:false %d:true\n", result, false, true);
	return (result);
}
