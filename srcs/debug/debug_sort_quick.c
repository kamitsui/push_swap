/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sort_quick.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:52:19 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 18:56:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "debug.h"

// disable when review
int	g_fd_log;
int	g_flag_debug;

void	debug_sort_quick_start(t_stack *src, t_stack *tmp, t_range range)
{
	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log,
			"---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
			range.low, range.high, src->top);
		ft_dprintf(g_fd_log, "mode[%d]  0:normal 1:reverse\n", range.mode);
		debug_data(g_fd_log, src, tmp);
	}
}

void	debug_sort_quick_end(t_stack *src, t_stack *tmp, t_range range)
{
	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log,
			"---- end time ---- range low[%d] ~ high[%d] ... \
\x9	\x9	\x9	src->top[%d] tmp->top[%d]\n",
			range.low, range.high, src->top, tmp->top);
		debug_data(g_fd_log, src, tmp);
	}
}
