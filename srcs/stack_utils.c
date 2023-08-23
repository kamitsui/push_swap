/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:38:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 14:31:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "push_swap.h"

/**
 * @brief スタックの容量が空かどうか調べる。
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 *
 * @return true:空, false:何か入っている
 */
bool	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

/**
 * @brief スタックの容量がMAXかどうか調べる。
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 *
 * @return true:容量MAX, false:空き容量あり
 */
bool	is_full(t_stack *stack)
{
	return (stack->top == MAX_SIZE - 1);
}
