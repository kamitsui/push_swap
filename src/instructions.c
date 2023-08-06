/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:50:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 23:30:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>// for printf

/**
 * @brief 命令 pa, pb : スタックsrcの先頭要素をdstへプッシュする
 *
 * @param dst : プッシュ先のスタック
 * @param src : プッシュ元のスタック
 */
void	push_data(t_Stack *dst, t_Stack *src)
{
	int	value;

	value = pop(src);
	push(dst, value);
	printf("p%s\n", dst->name);
}

/**
 * @brief 命令 sa, sb : スタックの先頭要素(top)と次の要素(top-1)を入れ替える
 *
 * @param stack type(t_Stack *) スタック構造体のポインタ
 */
static void	swap(t_Stack *stack)
{
	int temp;

	if (stack->top < 1)
	{
		printf("Error: Stack does not have enough elements to perform swap\n");
		return;
	}
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

/**
 * @brief 命令 sa, sb : スタックのswap ( top <-> top - 1 )
 *
 * @param target swapさせるスタック
 */
void	swap_one(t_Stack *target)
{
	swap(target);
	printf("s%s\n", target->name);
}

/**
 * @brief 命令 ss : ２つのスタックをswapする ( top <=> top - 1 )
 *
 * @param target1 swapさせるスタック1
 * @param target2 swapさせるスタック2
 */
void	swap_two(t_Stack *target1, t_Stack *target2)
{
	swap(target1);
	swap(target2);
	printf("ss\n");
}

/**
 * @brief スタックのローテーション ( 先頭 -> 末尾 )
 *
 * @param stack type(t_Stack *) スタックの構造体ポインタ
 */
static void	rotate(t_Stack *stack)
{
	int temp;

	if (isEmpty(stack))
	{
		printf("Error: Stack is empty, cannot rotate\n");
		return;
	}
	temp = stack->data[stack->top];
	for (int i = 0; i < stack->top; i++)
	{
		stack->data[stack->top - i] = stack->data[stack->top - 1 - i];
	}
	stack->data[0] = temp;
}

/**
 * @brief 命令 ra, rb : スタックのローテーション ( 先頭 -> 末尾 )
 *
 * @param target ローテーションさせる対象のスタック
 */
void	rotate_one(t_Stack *target)
{
	rotate(target);
	printf("r%s\n", target->name);
}

/**
 * @brief 命令 rr : ２つのスタックをローテーション ( 先頭 -> 末尾 )
 *
 * @param target1 ローテーションさせる対象のスタック
 * @param target2 ローテーションさせる対象のスタック
 */
void	rotate_two(t_Stack *target1, t_Stack *target2)
{
	rotate(target1);
	rotate(target2);
	printf("rr\n");
}
