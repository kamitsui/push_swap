/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:55:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 11:56:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_sorted.c
 * @brief スタックの整数がすでに昇順か否か調べる関数
 */
#include "push_swap.h"
#include <stdbool.h>

/**
 * @brief スタックの整数がすでに昇順か否か調べる関数
 *
 * @param stack 調べる対象データが入っているスタック構造体
 *
 * @return true:ソート済み false:ソートされていない
 */
bool	is_sorted(t_stack *stack)
{
	int	i;
	int	size;

	size = stack->top + 1;
	if (size <= 1)
		return (true);
	i = 0;
	while (i < size - 1)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (false);
		i++;
	}
	return (true);
}
