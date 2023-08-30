/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:30:10 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 17:04:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_rrr.c
 * @brief execute rrr & output "rrr\\n"
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

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

/**
 * @brief execute rrr & output "rrr\\n"
 *
 * @param stack_a to reverse rotate
 * @param stack_b to reverse rotate
 */
void	instruct_rrr(t_stack *stack_a, t_stack *stack_b)
{
	execute_rrr(stack_a, stack_b);
	ft_printf("rrr\n");
}
