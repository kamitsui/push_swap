/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 13:03:11 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_stack.c
 * @brief initialize the stack
 */
#include "push_swap.h"

/**
 * @brief initialize the stack
 *
 * @param stack to initialize
 * @param name is stack name
 */
void	init_stack(t_stack *stack, char *name)
{
	stack->top = -1;
	stack->name = name;
}
