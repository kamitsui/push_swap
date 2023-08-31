/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_rx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 11:56:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_rx.c
 * @brief execute ( ra | rb ) & output ( "ra\n" | "rb\n" )
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
static void	execute_rx(t_stack *stack)
{
	int	temp;
	int	i;

	if (is_empty(stack))
	{
		ft_printf(MSG_ERR_ROTATE);
		return ;
	}
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
 * @brief execute ( ra | rb ) & output ( "ra\n" | "rb\n" )
 *
 * @param target to rotate
 */
void	instruct_rx(t_stack *target)
{
	execute_rx(target);
	ft_printf("r%s\n", target->name);
}
