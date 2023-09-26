/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_less_than_stack_range.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 07:19:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 20:24:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_less_than_in_stack.c
 * @brief Check if a is less than b
 */
#include "push_swap.h"
#include <stdbool.h>
#include "ft_printf.h"

//for debug
//#include "debug.h"

//debug code
//static void	debug_is_less_than_stack_range(int data, int pivot_data)
//{
//	ft_dprintf(g_fd_log, "---- pivot_data[%d] > data[%d] ... result[%d]\n",
//		pivot_data, data, data < pivot_data);
//}

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
		if (pivot_data > stack->data[high - i])
		{
			result = true;
			break ;
		}
		i++;
	}
	return (result);
}
//debug code
//whileループ内でbreakの条件をデバッグ出力する
//		if (g_flag_debug == DEBUG_ON)
//			debug_is_less_than_stack_range(stack->data[high - i], pivot_data);
