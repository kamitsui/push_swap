/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:26:24 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 19:04:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

// for debug
#include "debug.h"
#include "ft_printf.h"
int	g_fd_log;
int	g_flag_debug;

// debug function
void	debug_range(t_range range)
{
	ft_dprintf(g_fd_log, "range  low[%d] high[%d]\n",
		range.low, range.high);
}

// debug function
void	debug_before_range(t_range range)
{
	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log, ">> before -- ");
		debug_range(range);
	}
}

// debug function
void	debug_after_range(t_range range)
{
	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log, ">> after -- ");
		debug_range(range);
	}
}
