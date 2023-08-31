/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 15:09:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_rr.c
 * @brief execute instruction rr
 */
#include "push_swap.h"
#include "instruct.h"

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
