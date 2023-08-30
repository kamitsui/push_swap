/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_sx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:50:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 15:52:45 by kamitsui         ###   ########.fr       */
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
void	execute_sx(t_stack *stack)
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
 * @brief execute ( sa | sb ) & output ( "sa\\n" | "sb\\n" )
 *
 * @param target : Swap the first 2 elements at the top of stack
 */
void	instruct_sx(t_stack *target)
{
	execute_sx(target);
	ft_printf("s%s\n", target->name);
}
