/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:15:48 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/23 21:07:34 by kamitsui         ###   ########.fr       */
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
void	end_process(t_stack *src, t_stack *tmp, t_range range, t_count count)
{
	int	i;

	if ((is_sorted_range(src, 0, src->top) == true
			&& is_empty(tmp) == true && range.mode == MODE_NORMAL)
			|| (is_sorted_range(tmp, 0, tmp->top) == true
			&& is_empty(src) == true && range.mode == MODE_REVERSE))
		return ;
	if (range.mode == MODE_REVERSE
		&& is_sorted_range(src, 0, src->top))
		//&& is_reverse_sorted_range(src, 0, src->top))// 9/22以前
		//&& is_sorted_range(tmp, 0, tmp->top))
		//&& is_sorted_range(tmp, original_tmp_top, tmp->top))
	{
		debug_put_message(range.mode);//debug
		while (is_empty(src) == false)
		{
			instruct_px(tmp, src);
			instruct_rx(tmp);
		}
		(void)count;// 仮
		// 9/23 無効化　実験　run2.sh
		//if (is_sorted_range(tmp, tmp->top - count.over, tmp->top) == true
		//	&& count.over > 0)
		//{
		//	i = 0;
		//	ft_dprintf(g_fd_log, ">> tmp->top - count.over [%d]\n", tmp->top - count.over);
		//	while (i++ < count.over)
		//		instruct_rx(tmp);
		//}
// 9/22以前
//				instruct_px(tmp, src);
//		if (is_sorted_range(tmp, 0, tmp->top) == true)
//		{
//			while (is_empty(src) == false)
//				instruct_px(tmp, src);
//			return ;
//		}
//		if (is_sorted_range(tmp, original_tmp_top, tmp->top) == true)
//		{
//			//while (tmp->top > original_tmp_top)// OK
//			while (tmp->top > original_tmp_top)// OK
//				instruct_px(src, tmp);
//			return ;
//		}
	}
	else if (range.mode == MODE_NORMAL
		//&& is_reverse_sorted_range(tmp, 0, tmp->top)// 9/22以前
		&& is_sorted_range(src, range.low, src->top))
	{
		debug_put_message(range.mode);//debug
		// tmp側がreverse_sortedの場合、stack_aの末尾に移動する。
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
		// tmp側がsortedの場合、stack_aの末尾に移動させる。
		if (is_sorted_range(tmp, 0, tmp->top) == true)
		{
			while (is_empty(tmp) == false)
			{
				instruct_px(src, tmp);
				instruct_rrx(src);
			}
		}
		// bottom側のソート後のデータを、stack_aの末尾に移動　（不要では）
		// 9/23 無効化 実験
		//if (is_sorted_range(src, range.low, src->top) == true)
		//if (is_sorted_range(src, src->top - count.over + 1, src->top) == true)
		//{
		//	i = 0;
		//	//while (i++ < range.high - range.low + 1)
		//	while (i++ < count.over)
		//		instruct_rx(src);
		//}
	}
	else
		return ;
	//(void)original_tmp_top;
}
//debug code
//end_process関数が走ったか確認する
//	if (g_flag_debug == DEBUG_ON)// debug
//		ft_dprintf(g_fd_log, ">> end_process from mode[%d]\n",
//			mode);
//end_processの条件に入ったかデバッグする
//		debug_put_message(mode);//debug
