/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_move_large_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:53:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 19:10:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "instruct.h"
#include "debug.h"
#include "ft_printf.h"

//// rotate する回数をデバッグ
//void	debug_number_of_ra(t_stack *src, t_count count)
//{
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log,
//			">> number of rotate ... src->top - count.over = %d\n",
//			src->top - count.over);
//}
//
//// reverse rotate する回数をデバッグ
//void	debug_number_of_rra(t_count count)
//{
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log,
//			">> number of rra ... count.over [%d]\n", count.over);
//}
//
//// move するデータをデバッグ
//void	debug_move_large_data(t_stack *src)
//{
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log,
//			">> move large data ... src->data[0] = %d\n", src->data[0]);
//}
