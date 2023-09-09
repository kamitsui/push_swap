/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:50:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/08 07:06:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_swap.c
 * @brief execute ( sa | sb ) & output ( "sa\\n" | "sb\\n" )
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

int	flag_debug;//debug
int	fd_log;// debug

/**
 * @brief execute ( sa | sb ) & output ( "sa\\n" | "sb\\n" )
 *
 * @param target : Swap the first 2 elements at the top of stack
 */
void	instruct_sx(t_stack *target)
{
	execute_sx(target);
	ft_printf("s%s\n", target->name);
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "s%s\n", target->name);// debug
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
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "ss\n");// debug
}
