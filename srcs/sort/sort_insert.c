/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:55:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 19:18:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort_insert.c
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
void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	int	current_element;

	while (!is_empty(stack_a))
	{
		current_element = peek(stack_a);
		while (!is_empty(stack_b)
			&& is_less_than(current_element, stack_b->data[stack_b->top]))
		{
			instruct_px(stack_a, stack_b);
			instruct_sx(stack_a);
		}
		instruct_px(stack_b, stack_a);
	}
	while (!is_empty(stack_b))
	{
		instruct_px(stack_a, stack_b);
	}
}
