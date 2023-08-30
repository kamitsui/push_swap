/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 17:09:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_px.c
 * @brief execute ( pa | pb ) & output ( "pa\n" | "pb\n" )
 */
#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief execute instruction ( pa | pb )
 *
 * @param dst : push one element to "dst" stack
 * @param src : pop first element from "src" stack
 */
static void	execute_px(t_stack *dst, t_stack *src)
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

/**
 * @brief execute ( pa | pb ) & output ( "pa\n" | "pb\n" )
 *
 * @param dst : push one element to "dst" stack
 * @param src : pop first element from "src" stack
 */
void	instruct_px(t_stack *dst, t_stack *src)
{
	execute_px(dst, src);
	ft_printf("p%s\n", dst->name);
}
