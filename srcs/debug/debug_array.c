/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:13:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/22 13:14:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "ft_printf.h"

int	g_fd_log;
int	g_flag_debug;

// デバッグ用の関数
void	debug_array(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log, "arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log, "\n");
}
