/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:10:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 20:40:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"

void	sort_two_elements(t_stack *stack_a)
{
	if (is_less_than(stack_a->data[0], stack_a->data[stack_a->top]) == true)
		instruct_sx(stack_a);
}

void	sort_three_elements(t_stack *stack_a)
{
	if (stack_a->top == 2)
	{
		if (stack_a->data[0] < stack_a->data[1]
			&& stack_a->data[1] < stack_a->data[2])
		{
			instruct_rx(stack_a);
			instruct_sx(stack_a);
		}
		else if (stack_a->data[0] < stack_a->data[1]
			&& stack_a->data[0] > stack_a->data[2])
		{
			instruct_rrx(stack_a);
			instruct_sx(stack_a);
		}
		else if (stack_a->data[0] < stack_a->data[1]
			&& stack_a->data[1] > stack_a->data[2])
			instruct_rrx(stack_a);
		else if (stack_a->data[0] > stack_a->data[1]
			&& stack_a->data[0] > stack_a->data[2])
			instruct_sx(stack_a);
		else if (stack_a->data[0] > stack_a->data[1]
			&& stack_a->data[1] < stack_a->data[2])
			instruct_rx(stack_a);
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	if (size <= 2)
		sort_two_elements(stack_a);
	else if (size <= 3)
		sort_three_elements(stack_a);
	else
		sort_insert(stack_a, stack_b);
		//sort_six_elements(stack_a, stack_b);
}
