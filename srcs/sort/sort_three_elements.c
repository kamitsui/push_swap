/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:49:12 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/16 15:50:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"

// for debug
#include "ft_printf.h"
#include <unistd.h>
#include "debug.h"

static void	rotable_sort_three_elements(t_stack *stack)
{
	if (is_reverse_sorted_range(stack, 0, stack->top))
	{
		instruct_rx(stack);
		instruct_sx(stack);
	}
	if (is_less_than(stack->data[2], stack->data[0]) == true
		&& is_less_than(stack->data[0], stack->data[1]) == true)
	{
		instruct_rrx(stack);
		instruct_sx(stack);
	}
	if (is_less_than(stack->data[0], stack->data[2]) == true
		&& is_less_than(stack->data[2], stack->data[1]) == true)
		instruct_rrx(stack);
	if (is_less_than(stack->data[1], stack->data[2]) == true
		&& is_less_than(stack->data[2], stack->data[0]) == true)
		instruct_sx(stack);
	if (is_less_than(stack->data[1], stack->data[0]) == true
		&& is_less_than(stack->data[0], stack->data[2]) == true)
		instruct_rx(stack);
}

//static void	rotate_disable_sort_three_elements(t_stack *stack)
//{
//}

void	sort_three_elements(t_stack *stack)
{
	if (stack->top == 2)
		rotable_sort_three_elements(stack);
//	else
//		rotate_disable_sort_three_elements(stack);
}
