/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_get_pivot_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:56:26 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 19:09:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quick_sort.h"
#include "debug.h"
#include "ft_printf.h"

//void	debug_get_pivot_data_start(t_range range, int size)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log,
//			">> call get_pivot_data function low[%d]~high[%d] size[%d]\n",
//			range.low, range.high, size);
//	}
//}
//
//// ----------------------------------------------
//// median, mid1, mid2を出力 （配列要素数が偶数の時）
//// ----------------------------------------------
//void	debug_median_even(long mid1, long mid2, int median)
//{
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, "mid1[%ld] mid2[%ld]\n", mid1, mid2);
//		ft_dprintf(g_fd_log, "median [%d]  ...  even\n", median);
//	}
//}
//
//// ----------------------------------------------
//// medianを出力 (配列要素数が奇数の時）
//// ----------------------------------------------
//void	debug_median_odd(int median)
//{
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log, "median [%d]  ... odd\n", median);
//}
