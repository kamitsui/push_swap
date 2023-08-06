/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:50:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 22:22:39 by kamitsui         ###   ########.fr       */
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
void	swap(t_Stack *stack)
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
	printf("s%s\n", stack->name);
}

/**
 * @brief 命令 ra, rb : スタックの先頭要素を末尾へ移動 ( top -> 0 )
 *
 * @param stack type(t_Stack *) スタックの構造体ポインタ
 */
void	rotate(t_Stack *stack)
{
	int temp;

	if (isEmpty(stack))
	{
		printf("Error: Stack is empty, cannot rotate\n");
		return;
	}
	temp = stack->data[0];
	for (int i = 0; i < stack->top; i++)
	{
		stack->data[i] = stack->data[i + 1];
	}
	stack->data[stack->top] = temp;
	printf("r%s\n", stack->name);
}
