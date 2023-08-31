/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:00:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 15:06:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_ra.c
 * @brief execute instruction ra
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

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
