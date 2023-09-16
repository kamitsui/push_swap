/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 06:41:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/16 17:11:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_sorted_range.c
 * @brief スタックの整数がすでに昇順か否か調べる関数(範囲指定バージョン)
 */
#include "push_swap.h"
#include <stdbool.h>

//// for debug
//#include "debug.h"
//#include "ft_printf.h"
//
//int	g_fd_log;
//int	g_flag_debug;

/**
 * @brief スタックの整数がすでに昇順か否か調べる関数(範囲指定バージョン)
 *
 * @param stack 調べる対象データが入っているスタック構造体
 *
 * @return true:ソート済み false:ソートされていない
 */
bool	is_sorted_range(t_stack *stack, int low, int high)
{
	int	i;
	int	size;

	size = high - low;
	if (size < 0)
		return (true);
	i = 0;
	while (i < size)
	{
		if (stack->data[low + i] < stack->data[low + i + 1])
			return (false);
		i++;
	}
	return (true);
}
//debug code
//	if (g_flag_debug == DEBUG_ON)
//	ft_dprintf(g_fd_log, ">> low[%d] high[%d] size[%d]\n", low, high, size);
