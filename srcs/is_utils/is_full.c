/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:56:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 11:58:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_full.c
 * @brief スタックの容量がBUFF_SIZEかどうか調べる。
 */
#include "push_swap.h"
#include <stdbool.h>

/**
 * @brief スタックの容量がBUFF_SIZEかどうか調べる。
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 *
 * @return true:容量BUFF_SIZE, false:空き容量あり
 */
bool	is_full(t_stack *stack)
{
	return (stack->top == BUFF_SIZE - 1);
}
