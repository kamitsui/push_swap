/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:26:24 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 19:11:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

// for debug
#include "debug.h"
#include "ft_printf.h"

//// rangeの範囲をデバッグ
//void	debug_range(t_range range)
//{
//	ft_dprintf(g_fd_log, "range  low[%d] high[%d]\n",
//		range.low, range.high);
//}
//
//// 再帰前のrangeをデバッグ
//void	debug_before_range(t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, ">> before -- ");
//		debug_range(range);
//	}
//}
//
//// 再帰に渡す新しいrangeをデバッグ
//void	debug_after_range(t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, ">> after -- ");
//		debug_range(range);
//	}
//}
//
//// 再帰がtop側かbottom側のどちらから呼び出されたかデバッグ
//void	debug_recursive(t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		if (range.mode == TOP_SIDE)
//			ft_dprintf(g_fd_log,
//				">> call recursive sort_quick func ... top side mode[%d]\n",
//				range.mode);
//		else
//			ft_dprintf(g_fd_log,
//				">> call recursive sort_quick func ... bottom side mode[%d]\n",
//				range.mode);
//	}
//}
