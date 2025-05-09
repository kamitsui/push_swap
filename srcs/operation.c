/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:46:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/28 22:08:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"
#include "ft_printf.h"

/**
 * @brief スタックからdata[top]の値をポップする（取り出す＋削除）
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 *
 * @return value type(int) ポップされた値
 */
int	pop(t_stack *stack)
{
	int	value;

	if (is_empty(stack))
		handle_error(ERR_POP);
	value = stack->data[stack->top];
	stack->top--;
	return (value);
}

/**
 * @brief スタックに値をプッシュする（先頭要素に値を入れる）
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 * @param value type(int) スタックに追加する値
 */
// Function to push an element onto the stack
void	push(t_stack *stack, int value)
{
	if (is_full(stack))
		handle_error(ERR_PUSH);
	stack->top++;
	stack->data[stack->top] = value;
}

/**
 * @brief スタックから先頭要素(data[top])を削除せずに値を取り出す。
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 *
 * @return 取り出した値
 */
int	peek(t_stack *stack)
{
	if (is_empty(stack))
		handle_error(ERR_PEEK);
	return (stack->data[stack->top]);
}
