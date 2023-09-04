/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:04:48 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 15:39:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_reverse_rotate.c
 * @brief execute instruction ( rra | rrb )
 */
#include "push_swap.h"
#include "error.h"
#include "ft_printf.h"

/**
 * @brief execute instruction ( rra | rrb )
 *
 * @param stack to reverse rotate
 * @details
 * Shift down all elements of stack by 1.\n
 * The last element becomes the 1st element in stack.\n
 */
void	execute_rrx(t_stack *stack)
{
	int	temp;
	int	i;

	if (is_empty(stack))
	{
		ft_printf(MSG_ERR_REVERSE_ROTATE);
		return ;
	}
	temp = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = temp;
}

/**
 * @brief execute instruction rra ( for using checker )
 *
 * @param stack_a is target to revert rotate
 * @param stack_b does nothing
 */
void	execute_rra(t_stack *stack_a, t_stack *stack_b)
{
	execute_rrx(stack_a);
	(void)stack_b;
}

/**
 * @brief execute instruction rrb ( for using checker )
 *
 * @param stack_a does nothing
 * @param stack_b is target to revert rotate
 */
void	execute_rrb(t_stack *stack_a, t_stack *stack_b)
{
	execute_rrx(stack_b);
	(void)stack_a;
}

/**
 * @brief execute instruction rrr
 *
 * @param stack_a to reverse rotate
 * @param stack_b to reverse rotate
 */
void	execute_rrr(t_stack *stack_a, t_stack *stack_b)
{
	execute_rra(stack_a, stack_b);
	execute_rrb(stack_a, stack_b);
}
