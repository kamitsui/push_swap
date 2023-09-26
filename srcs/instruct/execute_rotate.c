/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:58:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 19:30:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_rotate.c
 * @brief execute instruction ( ra | rb )
 */
#include "push_swap.h"
#include "error.h"
#include "ft_printf.h"

/**
 * @brief execute instruction ( ra | rb )
 *
 * @param stack to rotate
 * Shift up all elements of stack by 1.\n
 * The 1st element becomes the last element in stack.\n
 */
void	execute_rx(t_stack *stack)
{
	int	temp;
	int	i;

	if (is_empty(stack))
		handle_error(ERR_ROTATE);
	temp = stack->data[stack->top];
	i = 0;
	while (i < stack->top)
	{
		stack->data[stack->top - i] = stack->data[stack->top - 1 - i];
		i++;
	}
	stack->data[0] = temp;
}

/**
 * @brief execute instruction ra
 *
 * @param stack_a is target to rotate
 * @param stack_b does nothing
 */
void	execute_ra(t_stack *stack_a, t_stack *stack_b)
{
	execute_rx(stack_a);
	(void)stack_b;
}

/**
 * @brief execute instruction rb
 *
 * @param stack_a does nothing
 * @param stack_b is target to rotate
 */
void	execute_rb(t_stack *stack_a, t_stack *stack_b)
{
	execute_rx(stack_b);
	(void)stack_a;
}

/**
 * @brief execute instruction rr
 *
 * @param stack_a to rotate
 * @param stack_b to rotate
 */
void	execute_rr(t_stack *stack_a, t_stack *stack_b)
{
	execute_ra(stack_a, stack_b);
	execute_rb(stack_a, stack_b);
}
