/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_sx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:50:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 11:48:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_sx.c
 * @brief execute ( sa | sb ) & output ( "sa\\n" | "sb\\n" )
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
static void	execute_sx(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
	{
		ft_printf(MSG_ERR_SWAP);
		return ;
	}
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
 * @brief execute ( sa | sb ) & output ( "sa\\n" | "sb\\n" )
 *
 * @param target : Swap the first 2 elements at the top of stack
 */
void	instruct_sx(t_stack *target)
{
	execute_sx(target);
	ft_printf("s%s\n", target->name);
}
