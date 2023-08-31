/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:30:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 12:08:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_ss.c
 * @brief execute ss & output "ss\n"
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

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

/**
 * @brief execute ss & output "ss\n"
 *
 * @param stack_a : Swap the first 2 elements at the top of stack_a stack
 * @param stack_b : Swap the first 2 elements at the top of stack_b stack
 */
void	instruct_ss(t_stack *stack_a, t_stack *stack_b)
{
	execute_ss(stack_a, stack_b);
	ft_printf("ss\n");
}
