/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_end_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:01:10 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 11:24:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "ft_printf.h"

// end_processがtop側,bottom側のどちらから呼ばれたかをデバッグする
void	debug_end_process_start(int mode)
{
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log,
			">> move sorted data ... from mode[%d]  bottom[%d] top[%d]\n",
			mode, BOTTOM_SIDE, TOP_SIDE);
}
