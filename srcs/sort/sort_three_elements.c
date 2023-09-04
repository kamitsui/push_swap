/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:49:12 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 20:50:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"

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
