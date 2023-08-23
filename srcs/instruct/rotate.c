/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 09:23:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief スタックのローテーション ( 先頭 -> 末尾 )
 *
 * @param stack type(t_stack *) スタックの構造体ポインタ
 */
static void	rotate(t_stack *stack)
{
	int temp;

	if (isEmpty(stack))
	{
		ft_printf("Error: stack is empty, cannot rotate\n");
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
void	rotate_one(t_stack *target)
{
	rotate(target);
	ft_printf("r%s\n", target->name);
}

/**
 * @brief 命令 rr : ２つのスタックをローテーション ( 先頭 -> 末尾 )
 *
 * @param target1 ローテーションさせる対象のスタック
 * @param target2 ローテーションさせる対象のスタック
 */
void	rotate_two(t_stack *target1, t_stack *target2)
{
	rotate(target1);
	rotate(target2);
	ft_printf("rr\n");
}
