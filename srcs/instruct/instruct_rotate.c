/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:50:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/08 07:09:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_rotate.c
 * @brief instruction rotate
 * ( ra | rb | rr | rra | rrb | rrr )
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

int	flag_debug;//debug
int	fd_log;// debug

/**
 * @brief execute ( ra | rb ) & output ( "ra\n" | "rb\n" )
 *
 * @param target to rotate
 */
void	instruct_rx(t_stack *target)
{
	execute_rx(target);
	ft_printf("r%s\n", target->name);
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "r%s\n", target->name);// debug
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
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "rr\n");// debug
}

/**
 * @brief execute ( ra | rb ) & output ( "rra\n" | "rrb\n" )
 *
 * @param target to reverse rotate
 */
void	instruct_rrx(t_stack *target)
{
	execute_rrx(target);
	ft_printf("rr%s\n", target->name);
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "rr%s\n", target->name);// debug
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
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "rrr\n");// debug
}
