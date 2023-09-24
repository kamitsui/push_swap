/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_top_side.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:24:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 21:14:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

// for debug
//#include "debug.h"
//#include "ft_printf.h"
//
//int	g_fd_log;
//int	g_flag_debug;

// debug function
//static void	debug_top_side(t_range range)
//{
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log,
//			">> call recursive sort_quick func -- top side -- from mode[%d]\n",
//			range.mode);
//}

//void	recursive_top_side(t_stack *src, t_stack *tmp, t_range range)
void	recursive_top_side(t_stack *src, t_stack *tmp, t_range range, t_count count)
{
//	debug_top_side(range);
	if (range.mode == MODE_REVERSE)
	{
//		debug_before_range(range);
		range.low = 0;
		range.high = src->top;
		init_count(&count);
//		debug_after_range(range);
		sort_quick(src, tmp, range, count);
	}
	else
	{
//		debug_before_range(range);
		range.low = 0;
		range.high = tmp->top;
		range.mode = MODE_REVERSE;
		init_count(&count);
//		debug_after_range(range);
		sort_quick(tmp, src, range, count);
	}
}
//debug code
//recursive_top_side関数が走ったかデバッグ
//	debug_top_side(range);
//元のrangeをデバッグ
//		debug_before_range(range);
//再帰用にセットされたrangeをデバッグ
//		debug_after_range(range);
