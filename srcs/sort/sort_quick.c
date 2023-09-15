/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 11:43:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include "debug.h"// for debug
#include "ft_printf.h"// debug
#include <stdbool.h>
#include <stdlib.h>// debug

#include <unistd.h>// debug
#include <fcntl.h>//debug

int	fd_log;// for debug
int	flag_debug;// for debug

// TOP側が sorted なら、 reverse_sort する(stack_b側は常に逆順にしたい)
//void	reverse_sort(t_stack *src, t_stack *tmp, t_range range)
//{
//	if (is_sorted_range(tmp, 0, tmp->top) == true)
//	{
//		// TOP側のデータを逆ソートにする　src 側に入る。
//		i = 0;
//		while (i < count.less)
//		{
//			if (i < count.less - 1)
//				instruct_rrx(tmp);
//			instruct_px(src, tmp);
//			i++;
//		}
//		if (flag_debug == 1)// debug
//		{
//			ft_dprintf(fd_log, "-- range low[%d] high[%d] pi[%d]\n",
//					range->low, range->high, range->pi);
//			ft_dprintf(fd_log, "---- end partision_reverse ----\n");
//			debug_data(fd_log, src, tmp);
//		}
//		return ;
//	}
//}

void	end_process(t_stack *src, t_stack *tmp, int mode)
{
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, ">> end_process from mode[%d]\n",
			mode);
	if (mode == 1
			&& is_reverse_sorted_range(src, 0, src->top)
			&& is_sorted_range(tmp, 0, tmp->top))
	{
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, ">> move sorted data\n");
		while (is_empty(src) == false)
			instruct_px(tmp, src);
	}
	else if (mode == 0
			&& is_reverse_sorted_range(tmp, 0, tmp->top)
			&& is_sorted_range(src, 0, src->top))
	{
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, ">> move sorted data\n");
		while (is_empty(tmp) == false)
			instruct_px(src, tmp);
	}
	else
		return ;
}

void	recursive_top_side(t_stack *src, t_stack *tmp, t_range range,
		int original_tmp_top)
{
	if (flag_debug == 1)// for debug
	{
		ft_dprintf(fd_log,
			">> call recursive sort_quick func -- top side -- from mode[%d]\n",
			range.mode);
	}
	if (range.mode == 1)
	{
		ft_dprintf(fd_log, ">> before -- range low[%d] high[%d]\n", range.low, range.high);
		range.low = 0;
		range.high = src->top;
		ft_dprintf(fd_log, ">> after -- range low[%d] high[%d]\n", range.low, range.high);
		sort_quick(src, tmp, range);
	}
	else
	{
		ft_dprintf(fd_log, ">> before -- range low[%d] high[%d]\n", range.low, range.high);
		range.low = original_tmp_top;
		//range.low = 0;
		range.high = tmp->top;
		range.mode = MODE_REVERSE;
		ft_dprintf(fd_log, ">> after -- range low[%d] high[%d]\n", range.low, range.high);
		sort_quick(tmp, src, range);
	}
}

void	recursive_bottom_side(t_stack *src, t_stack *tmp, t_range range,
		int original_tmp_top)
{
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log,
			">> call recursive sort_quick func -- bottom side -- from mode[%d]\n",
			range.mode);
	if (range.mode == 1)
	{
		//instruct_px(src, tmp);
		range.low = original_tmp_top + 1;
		range.high = tmp->top;
		range.mode = MODE_NORMAL;
		sort_quick(tmp, src, range);
	}
	else
	{
		instruct_px(tmp, src);
		//range.low += 1;
		range.high = src->top;
		sort_quick(src, tmp, range);
	}
}

void	sort_quick(t_stack *src, t_stack *tmp, t_range range)
{
	int	original_tmp_top;
	static t_f_is_sorted_direction	is_sorted_direction[2] = {
			is_sorted_range, is_reverse_sorted_range};
	flag_debug = 1;//debug

	original_tmp_top = tmp->top * (is_empty(tmp) == false);

	// 再帰の終了条件　rangeのデータ１個だけ || range内がソート済みなら
	if (range.low >= range.high
			|| is_sorted_direction[range.mode](src, range.low, range.high) == true)
	{
		//if (range.mode == 0 && (range.low > 0)
		//		&& (is_sorted_range(src, 0, range.low - 1) == false))
		//{
		//	while (src->top >= range.low)
		//		instruct_px(tmp, src);
		//}
		return ;
	}

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log,
			"---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
			range.low, range.high, src->top);// for debug
		ft_dprintf(fd_log, "mode[%d]  0:normal 1:reverse\n", range.mode);
		debug_data(fd_log, src, tmp);// for debug
	}

// -----------------------------------------------------------
	// partition　high を pivot_dataとして、分割する関数
	if (range.mode == 0)
		partition(src, tmp, range);
	else
		partition_reverse(src, tmp, range);
// -----------------------------------------------------------

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log, ">> after partition func\n");
		debug_data(fd_log, src, tmp);
	}

	if (flag_debug == 1)// debug
	{
		ft_dprintf(fd_log, "range  low[%d] high[%d]\n",
				range.low, range.high);
	}

	if (is_sorted_direction[range.mode](src, 0, src->top) == true
			&& is_sorted_direction[range.mode == MODE_NORMAL](tmp, 0, tmp->top) == true)
		end_process(src, tmp, range.mode);

	recursive_top_side(src, tmp, range, original_tmp_top);
	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log,
			"---- end recursive_top_side ---- range low[%d] ~ high[%d] ... src->top[%d] tmp->top[%d] mode[%d]\n",
			range.low, range.high, src->top, tmp->top, range.mode);
	}
	recursive_bottom_side(src, tmp, range, original_tmp_top);
	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log,
			"---- end recursive_bottom_side ---- range low[%d] ~ high[%d] ... src->top[%d] tmp->top[%d] mode[%d]\n",
			range.low, range.high, src->top, tmp->top, range.mode);
	}

//	if (range.mode == 1)
//	{
//		ft_dprintf(fd_log, "exit\n");
//		exit(0);
//	}


// -----------------  top側のデータを戻す
	end_process(src, tmp, range.mode);

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log,
			"---- end time ---- range low[%d] ~ high[%d] ... src->top[%d] tmp->top[%d]\n",
			range.low, range.high, src->top, tmp->top);
		debug_data(fd_log, src, tmp);
	}
}
