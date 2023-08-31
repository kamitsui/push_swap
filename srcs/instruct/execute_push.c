/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:22:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 18:36:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_push.c
 * @brief execute ( pa | pb )
 */
#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief execute instruction ( pa | pb )
 *
 * @param dst : push one element to "dst" stack
 * @param src : pop first element from "src" stack
 */
void	execute_px(t_stack *dst, t_stack *src)
{
	int	value;

	value = pop(src);
	push(dst, value);
}

/**
 * @brief execute instruction pa ( only use in checker )
 *
 * @param stack_a
 * @param stack_b
 */
void	execute_pa(t_stack *stack_a, t_stack *stack_b)
{
	execute_px(stack_a, stack_b);
}

/**
 * @brief execute instruction pb ( only use in checker )
 *
 * @param stack_a
 * @param stack_b
 */
void	execute_pb(t_stack *stack_a, t_stack *stack_b)
{
	execute_px(stack_b, stack_a);
}
