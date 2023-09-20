/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:15:48 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/20 23:07:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

// for debug
#include "debug.h"
#include "ft_printf.h"

int	g_fd_log;
int	g_flag_debug;

// debug function
static void	debug_put_message(int mode)
{
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log, ">> move sorted data ... from mode[%d]\n", mode);
}

// スタックAがソート済み、スタックBが逆ソート済みの場合、終了プロセスが走る
// 処理内容：スタックBが空になるまでスタックAにpushする
//void	end_process(t_stack *src, t_stack *tmp, int mode)
void	end_process(t_stack *src, t_stack *tmp,
		int original_tmp_top, int mode)
{
	if (mode == 1
		&& is_reverse_sorted_range(src, 0, src->top))
		//&& is_sorted_range(tmp, 0, tmp->top))
		//&& is_sorted_range(tmp, original_tmp_top, tmp->top))
	{
		debug_put_message(mode);//debug
		if (is_sorted_range(tmp, 0, tmp->top) == true)
		{
			while (is_empty(src) == false)
				instruct_px(tmp, src);
			return ;
		}
		if (is_sorted_range(tmp, original_tmp_top, tmp->top) == true)
		{
			while (tmp->top > original_tmp_top)
				instruct_px(src, tmp);
			return ;
		}
	}
	else if (mode == 0
		&& is_reverse_sorted_range(tmp, 0, tmp->top)
		&& is_sorted_range(src, 0, src->top))
	{
		debug_put_message(mode);//debug
		while (is_empty(tmp) == false)
			instruct_px(src, tmp);
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
