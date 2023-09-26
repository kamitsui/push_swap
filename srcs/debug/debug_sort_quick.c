/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sort_quick.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:52:19 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 21:08:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "debug.h"

////sort_quick関数の開始状況をデバッグ
//void	debug_sort_quick_start(t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log,
//			"---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
//			range.low, range.high, src->top);
//		ft_dprintf(g_fd_log, "mode[%d]  0:normal 1:reverse\n", range.mode);
//		debug_data(g_fd_log, src, tmp);
//	}
//}
//
////sort_quick関数の終了状況をデバッグ
//void	debug_sort_quick_end(t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
/*
//		ft_dprintf(g_fd_log,
//			"---- end time ---- range low[%d] ~ high[%d] ... \
//\x9	\x9	\x9	src->top[%d] tmp->top[%d]\n",
//			range.low, range.high, src->top, tmp->top);
//		debug_data(g_fd_log, src, tmp);
*/
//	}
//}
//
////partition関数で分割された後の状態をデバッグ
//void	debug_after_partition(t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, ">> after partition func\n");
//		debug_data(g_fd_log, src, tmp);
//		debug_range(range);
//	}
//}
//
////top側の再帰ソートが終わった後の状態をデバッグ
//void	debug_after_recursive_top_side(
//		t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
/*
 *		ft_dprintf(g_fd_log,
 *			"---- end recursive_top_side ---- \
 *\x9	\x9	\x9	range low[%d] ~ high[%d] ... \
 *\x9	\x9	\x9	src->top[%d] tmp->top[%d] mode[%d]\n",
 *			range.low, range.high, src->top, tmp->top, range.mode);
*/
//	}
//}
//
////bottom側の再帰ソートが終わった後の状態をデバッグ
//void	debug_after_recursive_bottom_side(
//		t_stack *src, t_stack *tmp, t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
/*
 *		ft_dprintf(g_fd_log,
 *			"---- end recursive_bottom_side ---- \
 *\x9	\x9	\x9	range low[%d] ~ high[%d] ... \
 *\x9	\x9	\x9	src->top[%d] tmp->top[%d] mode[%d]\n",
 *			range.low, range.high, src->top, tmp->top, range.mode);
*/
//	}
//}
