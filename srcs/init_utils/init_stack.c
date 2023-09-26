/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 13:37:20 by kamitsui         ###   ########.fr       */
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
static void	set_initial_value(t_stack *stack, const char *name)
{
	stack->top = -1;
	stack->name = name;
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	set_initial_value(stack_a, "a");
	set_initial_value(stack_b, "b");
	stack_a->size = size;
	stack_b->size = size;
}
