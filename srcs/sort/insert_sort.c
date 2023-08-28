/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:55:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/28 16:05:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file insert_sort.c
 * @brief This sort function using the insertion sort algorithm
 */
#include "push_swap.h"
#include "instruct.h"

/**
 * @brief This sort function using the insertion sort algorithm
 *
 * @param stack_a is unsorted data.
 * @param stack_b is empty. (for sorting stack_a)
 */
void	insert_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	current_element;

	while (!is_empty(stack_a))
	{
		current_element = peek(stack_a);
		while (!is_empty(stack_b)
			&& is_less_than(current_element, stack_b->data[stack_b->top]))
		{
			push_data(stack_a, stack_b);
			swap_one(stack_a);
		}
		push_data(stack_b, stack_a);
	}
	while (!is_empty(stack_b))
	{
		push_data(stack_a, stack_b);
	}
}
