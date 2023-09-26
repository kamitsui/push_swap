/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:49:12 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 20:26:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"

static void	rotable_sort_three_elements(t_stack *stack)
{
	if (is_reverse_sorted_range(stack, 0, stack->top))
	{
		instruct_rx(stack);
		instruct_sx(stack);
	}
	else if (is_less_than(stack->data[2], stack->data[0]) == true
		&& is_less_than(stack->data[0], stack->data[1]) == true)
	{
		instruct_rrx(stack);
		instruct_sx(stack);
	}
	else if (is_less_than(stack->data[0], stack->data[2]) == true
		&& is_less_than(stack->data[2], stack->data[1]) == true)
		instruct_rrx(stack);
	else if (is_less_than(stack->data[1], stack->data[2]) == true
		&& is_less_than(stack->data[2], stack->data[0]) == true)
		instruct_sx(stack);
	else
		instruct_rx(stack);
}

void	sort_three_elements(t_stack *stack)
{
	if (stack->top == 2)
		rotable_sort_three_elements(stack);
}
