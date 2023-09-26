/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:13:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 19:08:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "ft_printf.h"

// デバッグ用の関数
//void	debug_array(int arr[], int size)
//{
//	int	i;
//
//	if (g_flag_debug == DEBUG_ON)
//	{
//		i = 0;
//		while (i < size)
//		{
//			ft_dprintf(g_fd_log, "arr[%d] = %d\n", i, arr[i]);
//			i++;
//		}
//		ft_dprintf(g_fd_log, "\n");
//	}
//}
//
//void	debug_array_before(int arr[], int size)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, "---- before ----\n");
//		debug_array(arr, size);
//	}
//}
//
//void	debug_array_after(int arr[], int size)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, "---- after ----\n");
//		debug_array(arr, size);
//	}
//}
