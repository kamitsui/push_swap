/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 11:03:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file init_stack.c
 * @brief スタックの初期化
 */
#include "push_swap.h"

/**
 * @brief スタックの初期化
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 */
void	init_stack(t_stack *stack, char *name)
{
	stack->top = -1;
	stack->name = name;
}

