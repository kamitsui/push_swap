/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:30:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 20:20:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_swap.c
 * @brief execute ( sa | sb | ss )
 */
#include "push_swap.h"
#include "instruct.h"
#include "error.h"
#include "ft_printf.h"

/**
 * @brief execute instruction ( sa | sb )
 *
 * @param stack : Swap the first 2 elements at the top of stack
 */
void	execute_sx(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
		handle_error(ERR_SWAP);
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

/**
 * @brief execute instruction sa ( for using checker )
 *
 * @param stack_a is target to swap
 * @param stack_b does nothing
 */
void	execute_sa(t_stack *stack_a, t_stack *stack_b)
{
	execute_sx(stack_a);
	(void)stack_b;
}

/**
 * @brief execute instruction sb ( for using checker )
 *
 * @param stack_a does nothing
 * @param stack_b is target to swap
 */
void	execute_sb(t_stack *stack_a, t_stack *stack_b)
{
	execute_sx(stack_b);
	(void)stack_a;
}

/**
 * @brief execute instruction ss
 *
 * @param stack_a : Swap the first 2 elements at the top of stack_a
 * @param stack_b : Swap the first 2 elements at the top of stack_b
 */
void	execute_ss(t_stack *stack_a, t_stack *stack_b)
{
	execute_sa(stack_a, stack_b);
	execute_sb(stack_a, stack_b);
}
