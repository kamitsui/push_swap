/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:26:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/16 21:51:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"

// for debug
#include "debug.h"
#include "ft_printf.h"

int	g_fd_log;
int	g_flag_debug;

void	partition_three_elements(t_stack *src, t_stack *tmp, t_range range)
{
	static t_f_is_sorted_direction	is_reverse_sorted_direction[2] = {
		is_reverse_sorted_range, is_sorted_range};
	static t_f_is_compare_than	is_compare_direction[2] = {
		is_less_than, is_more_than};
	int							mode;
	int	second;
	int	first;;
	int	zero;

	mode = range.mode;
	(void)range;
	second = src->top;
	first = src->top - 1;
	zero = src->top - 2;
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log,
			">> call partition_three_elements\n");
	if (is_reverse_sorted_direction[mode](src, zero, second) == true)
	{
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log,
				">> reverse mode[%d]\n", mode);
		instruct_sx(src);
		instruct_px(tmp, src);
		instruct_sx(src);
		instruct_px(tmp, src);
		return ;
	}
	else if (is_compare_direction[mode](src->data[second], src->data[zero]) == true
		&& is_compare_direction[mode](src->data[zero], src->data[first]) == true)
//	if (is_compare_direction[mode](src->data[second], src->data[zero]) == true
//		&& is_compare_direction[mode](src->data[zero], src->data[first]) == true)
	{
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log,
				">> push swap\n");
		instruct_px(tmp, src);
		instruct_sx(src);
		return ;
	}
	else if (is_compare_direction[mode](src->data[zero], src->data[second]) == true
		&& is_compare_direction[mode](src->data[second], src->data[first]) == true)
	{
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log,
				">> push swap push\n");
		instruct_px(tmp, src);
		instruct_sx(src);
		instruct_px(tmp, src);
		return ;
	}
	else if (is_compare_direction[mode](src->data[first], src->data[second]) == true
		&& is_compare_direction[mode](src->data[second], src->data[zero]) == true)
	{
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log,
				">> swap\n");
		instruct_sx(src);
		return ;
	}
	else if (is_compare_direction[mode](src->data[first], src->data[zero]) == true
		&& is_compare_direction[mode](src->data[zero], src->data[second]) == true)
	{
		if (g_flag_debug == DEBUG_ON)
			ft_dprintf(g_fd_log,
				">> swap push swap\n");
		instruct_sx(src);
		instruct_px(tmp, src);
		instruct_sx(src);
		return ;
	}
}

//void	partition_small(t_stack *src, t_stack *tmp, t_range range)
//{
//	if (range.high - range.low == 2)
//		partition_three_elements(src, tmp, range);
//}
