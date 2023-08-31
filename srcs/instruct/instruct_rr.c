/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:43:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 11:35:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_rr.c
 * @brief execute rr & output "rr\\n"
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

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

/**
 * @brief execute rr & output "rr\\n"
 *
 * @param stack_a to rotate
 * @param stack_b to rotate
 */
void	instruct_rr(t_stack *stack_a, t_stack *stack_b)
{
	execute_rr(stack_a, stack_b);
	ft_printf("rr\n");
}
