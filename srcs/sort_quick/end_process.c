/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:15:48 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:51:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include <stdbool.h>

// for debug
#include "debug.h"

// sort_quick関数の再帰によってpartitionで分けきれなくなったtop側のデータを
// stack_Aの末尾に移動する。（このデータは常に最小値である）
static void	end_process_top_side(t_stack *src, t_stack *tmp)
{
	while (is_empty(src) == false)
	{
		instruct_px(tmp, src);
		instruct_rx(tmp);
	}
}

// sort_quick関数の再帰後に、bottom側のデータがソートされてるデータを
// stack_Aの末尾に移動する。(昇順sorted or 降順reverse_sorted のみ実行する)
static void	end_process_bottom_side(t_stack *src, t_stack *tmp)
{
	int	i;

	if (is_reverse_sorted_range(tmp, 0, tmp->top) == true)
	{
		i = 0;
		while (is_empty(tmp) == false)
		{
			instruct_px(src, tmp);
			i++;
		}
		while (i-- > 0)
			instruct_rx(src);
	}
	if (is_sorted_range(tmp, 0, tmp->top) == true)
	{
		while (is_empty(tmp) == false)
		{
			instruct_px(src, tmp);
			instruct_rrx(src);
		}
	}
}

// sort_quick関数（top側とbottom側）の再帰後に、ソートされているデータを
// stack_Aの末尾に移動する。
void	end_process(t_stack *src, t_stack *tmp, t_range range)
{
	if ((is_sorted_range(src, 0, src->top) == true
			&& is_empty(tmp) == true && range.mode == BOTTOM_SIDE)
		|| (is_sorted_range(tmp, 0, tmp->top) == true
			&& is_empty(src) == true && range.mode == TOP_SIDE))
		return ;
	if (range.mode == TOP_SIDE
		&& is_sorted_range(src, 0, src->top))
		end_process_top_side(src, tmp);
	else if (range.mode == BOTTOM_SIDE
		&& is_sorted_range(src, range.low, src->top))
		end_process_bottom_side(src, tmp);
	else
		return ;
}
//debug code
//	debug_end_process_start(range.mode);
