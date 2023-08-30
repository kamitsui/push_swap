/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:38:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 11:58:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_empty.c
 * @brief スタックの容量が空かどうか調べる。
 */
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
