/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:46:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 21:02:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>// for printf

/**
 * @brief スタックからdata[top]の値をポップする（取り出す＋削除）
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 *
 * @return value type(int) ポップされた値
 */
int	pop(t_Stack *stack)
{
	int value;

	if (isEmpty(stack))
	{
		printf("Error: Stack is empty, cannot pop\n");
		exit (1);
	}
	value = stack->data[stack->top];
	stack->top--;
	return (value);
}

/**
 * @brief スタックに値をプッシュする（先頭要素に値を入れる）
 *
 * @param stack type(t_Stack *) スタック構造体のポインタ
 * @param value type(int) スタックに追加する値
 */
// Function to push an element onto the stack
void	push(t_Stack *stack, int value)
{
	if (isFull(stack))
	{
		printf("Error: Stack is full, cannot push %d\n", value);
		exit (1);
	}
	stack->top++;
	stack->data[stack->top] = value;
}

/**
 * @brief スタックから先頭要素(data[top])を削除せずに値を取り出す。
 *
 * @param stack type(t_Stack *) スタック構造体のポインタ
 *
 * @return 取り出した値
 */
int	peek(t_Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("Error: Stack is empty, cannot peek\n");
		exit (1);
	}
	return (stack->data[stack->top]);
}
