/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:50:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 09:24:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief 命令 <sa> or <sb> のヘルパー関数
 * スタックの先頭要素(top)と次の要素(top-1)を入れ替える
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 */
static void	swap(t_stack *stack)
{
	int temp;

	if (stack->top < 1)
	{
		ft_printf("Error: stack does not have enough elements to perform swap\n");
		return;
	}
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

/**
 * @brief 命令 <sa> or <sb> : スタックのswap ( top <-> top - 1 )
 *
 * @param target swapさせるスタック
 */
void	swap_one(t_stack *target)
{
	swap(target);
	ft_printf("s%s\n", target->name);
}

/**
 * @brief 命令 <ss> : ２つのスタックをswapする ( top <=> top - 1 )
 *
 * @param target1 swapさせるスタック1
 * @param target2 swapさせるスタック2
 */
void	swap_two(t_stack *target1, t_stack *target2)
{
	swap(target1);
	swap(target2);
	ft_printf("ss\n");
}
