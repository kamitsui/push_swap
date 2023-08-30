/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:30:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 15:57:36 by kamitsui         ###   ########.fr       */
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
 * @param target1 : Swap the first 2 elements at the top of target1 stack
 * @param target2 : Swap the first 2 elements at the top of target2 stack
 */
void	execute_ss(t_stack *target1, t_stack *target2)
{
	execute_sx(target1);
	execute_sx(target2);
}

/**
 * @brief execute ss & output "ss\n"
 *
 * @param target1 : Swap the first 2 elements at the top of target1 stack
 * @param target2 : Swap the first 2 elements at the top of target2 stack
 */
void	instruct_ss(t_stack *target1, t_stack *target2)
{
	execute_ss(target1, target2);
	ft_printf("ss\n");
}
