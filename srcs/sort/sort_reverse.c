/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:07:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/20 22:02:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include <stdbool.h>

//// for debug
#include "debug.h"
#include "ft_printf.h"

int	g_fd_log;
int	g_flag_debug;

// tmpのスタックにpushし、rotateをすることで逆ソートになる。
// 一番大きい値だけsrcのTOPに残す。→あくまでもpartitionとして扱うため
static void	rotable_tmp_stack(t_stack *src, t_stack *tmp, int size)
{
	int	i;

	instruct_rx(src);
	i = 0;
	while (i < size)
	{
		instruct_px(tmp, src);
		if (i > 0)
			instruct_rx(tmp);
		i++;
	}
	instruct_rrx(src);
}

// reverse rotate で小さい値をsrcスタックのTOPに持ってきて
// tmp側にpushする方法で逆ソートする
// 一番大きい値だけsrcのTOPに残す。→あくまでもpartitionとして扱うため
static void	rotable_src_stack(t_stack *src, t_stack *tmp, int size)
{
	int	i;

	ft_dprintf(g_fd_log, ">> call rotable_src_stack()\n");
	i = 0;
	while (i < size)
	{
		instruct_rrx(src);
		if (i < size - 1)
			instruct_px(tmp, src);
		i++;
	}
	instruct_sx(src);
	i = 0;
	while (i < size - 1)
	{
		instruct_px(src, tmp);
		i++;
	}
}

// 1.一番低い値がsrcのTOPにくるまでrotateする ra x size
// 2.一旦tmpに降順に値をプッシュする
//   pb+rra x size-1　（一番大きい要素だけsrcのTOPに残す）
// 3.paを繰り返して元に戻す pa x size-2
// 一番大きい値だけsrcのTOPに残す。→あくまでもpartitionとして扱うため
static void	rotate_disable(t_stack *src, t_stack *tmp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		instruct_rx(src);
		i++;
	}
	i = 0;
	while (i < size)
	{
		instruct_px(tmp, src);
		instruct_rrx(src);
		i++;
	}
}

//逆順に並び替えて、TOP以外はtmpスタックに送る
// 一番大きい値だけsrcのTOPに残す。→あくまでもpartitionとして扱うため
void	sort_reverse(t_stack *src, t_stack *tmp, int size)
{
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log, "sort_reverse\n");
	if (size == 1)
		instruct_sx(src);
	else if (is_empty(tmp) == true)
		rotable_tmp_stack(src, tmp, size);
	else if (size == src->top)
		rotable_src_stack(src, tmp, size);
	else
		rotate_disable(src, tmp, size);
}
