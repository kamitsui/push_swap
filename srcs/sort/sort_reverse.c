/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:07:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 19:17:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include <stdbool.h>
#include "debug.h"//debug
#include "ft_printf.h"//debug

int	g_fd_log;
int	g_flag_debug;

void	rotable_stack_b(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size + 1)
	{
		instruct_px(stack_b, stack_a);
		if (i > 0)
			instruct_rx(stack_b);
		i++;
	}
	debug_data(fd_log, stack_a, stack_b);
	i = 0;
	while (i < size + 1)
	{
		instruct_px(stack_a, stack_b);
		i++;
	}
}

// size + 1にした方がいいかも　呼び出し側で　保留
void	sort_reverse(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i;

	if (size == 1)
		instruct_sx(stack_a);
	else if (is_empty(stack_b) == true)
		rotable_stack_b(stack_a, stack_b, size);
	else if (size == stack_a->top)
	// rraで小さい値をTOPに持ってきてpbする方法で逆ソートする
	{
		i = 0;
		ft_dprintf(fd_log, "size[%d] stack_a->top[%d]\n", size, stack_a->top);
		while (i < size)
		{
			instruct_rrx(stack_a);
			if (i < size - 1)
				instruct_px(stack_b, stack_a);
			i++;
		}
		i = 0;
		while (i < size - 1)
		{
			instruct_px(stack_a, stack_b);
			i++;
		}
	}
	else
	// 1.一番低い値がstack_aのTOPにくるまでrotateする ra x size-1
	//2.一旦stack_bに降順に値をプッシュする
	//  pb+rra x size-1　（一番大きい要素だけstack_aのTOPに残す）
	//3.paを繰り返して元に戻す pa x size-2
	{
		i = 0;
		//while (i < size)
		while (i < size)
		{
			//instruct_rrx(stack_a);
			instruct_rx(stack_a);
			//if (i < size - 1)
			//	instruct_px(stack_b, stack_a);
			i++;
		}
		debug_data(fd_log, stack_a, stack_b);
		i = 0;
		while (i < size)
		{
			instruct_px(stack_b, stack_a);
			//if (i < size - 1)
			// run3.shでKOのため修正
				instruct_rrx(stack_a);
			i++;
		}
		i = 0;
		while (i < size)
		{
			instruct_px(stack_a, stack_b);
			i++;
		}
	}
}
