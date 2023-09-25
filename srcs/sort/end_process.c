/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:15:48 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 18:19:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

// for debug
//#include "debug.h"
//#include "ft_printf.h"
//
//int	g_fd_log;
//int	g_flag_debug;

// debug function
//static void	debug_put_message(int mode)
//{
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log, ">> move sorted data ... from mode[%d]\n", mode);
//}

// スタックAがソート済み、スタックBが逆ソート済みの場合、終了プロセスが走る
// 処理内容：スタックBが空になるまでスタックAにpushする
//void	end_process(t_stack *src, t_stack *tmp, int mode)
void	end_process(t_stack *src, t_stack *tmp, t_range range)
{
	int	i;

	if ((is_sorted_range(src, 0, src->top) == true
			&& is_empty(tmp) == true && range.mode == BOTTOM_SIDE)
			|| (is_sorted_range(tmp, 0, tmp->top) == true
			&& is_empty(src) == true && range.mode == TOP_SIDE))
		return ;
	if (range.mode == TOP_SIDE
		&& is_sorted_range(src, 0, src->top))
	{
//		debug_put_message(range.mode);//debug
		while (is_empty(src) == false)
		{
			instruct_px(tmp, src);
			instruct_rx(tmp);
		}
	}
	else if (range.mode == BOTTOM_SIDE
		&& is_sorted_range(src, range.low, src->top))
	{
//		debug_put_message(range.mode);//debug
		// top側がreverse_sortedの場合、stack_aの末尾に移動する。
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
		// top側がsortedの場合、stack_aの末尾に移動させる。
		if (is_sorted_range(tmp, 0, tmp->top) == true)
		{
			while (is_empty(tmp) == false)
			{
				instruct_px(src, tmp);
				instruct_rrx(src);
			}
		}
	}
	else
		return ;
}
//debug code
//end_process関数が走ったか確認する
//	if (g_flag_debug == DEBUG_ON)// debug
//		ft_dprintf(g_fd_log, ">> end_process from mode[%d]\n",
//			mode);
//end_processの条件に入ったかデバッグする
//		debug_put_message(mode);//debug
