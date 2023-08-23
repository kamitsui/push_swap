/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:50:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 14:21:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "error.h"
#include "ft_printf.h"

void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (is_empty(stack))
	{
		ft_printf(MSG_ERR_REVERSE_ROTATE);
		return ;
	}
	temp = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = temp;
}

/**
 * @brief 命令 ra, rb : スタックのローテーション 逆ver ( 末尾 -> 先頭 )
 *
 * @param target ローテーションさせる対象のスタック
 */
void	reverse_rotate_one(t_stack *target)
{
	reverse_rotate(target);
	ft_printf("rr%s\n", target->name);
}

/**
 * @brief 命令 rrr : ２つのスタックをローテーション　逆ver ( 末尾 -> 先頭 )
 *
 * @param target1 ローテーションさせる対象のスタック
 * @param target2 ローテーションさせる対象のスタック
 */
void	reverse_rotate_two(t_stack *target1, t_stack *target2)
{
	reverse_rotate(target1);
	reverse_rotate(target2);
	ft_printf("rrr\n");
}
