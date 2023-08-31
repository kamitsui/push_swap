/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:04:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 15:05:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_rb.c
 * @brief execute instruction rb
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

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
