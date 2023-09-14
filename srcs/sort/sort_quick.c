/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/14 11:47:56 by kamitsui         ###   ########.fr       */
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

void	recursive_top_side(t_stack *src, t_stack *tmp, t_range range)
{
	if (flag_debug == 1)// for debug
		ft_dprintf(fd_log, "mode[%d] 0:normal 1:reverse == false?\n",
			(range.flag & BIT_MODE_REVERSE) > 0);
	if ((range.flag & BIT_MODE_REVERSE) > 0)
	{
//		if (is_reverse_sorted_range(src, range.low, range.high) == false)
//		{
			if (flag_debug == 1)// for debug
			{
				ft_dprintf(fd_log,
						">> call recursive sort_quick func -- top side mode[%d]\n",
						(range.flag & BIT_MODE_REVERSE) > 0);
			}
			sort_quick(src, tmp, range);
//		}
//		else // check 用
//			ft_dprintf(fd_log,
//					">> don't call recursive sort_quick func -- top side\n");
	}
	else
	{
		if (is_reverse_sorted_range(tmp, range.low, range.high) == false)
		{
			range.flag = BIT_UNSORTED | BIT_MODE_REVERSE;
			if (flag_debug == 1)// for debug
			{
				ft_dprintf(fd_log,
						">> call recursive sort_quick func -- top side\n");
			}
			sort_quick(tmp, src, range);
		}
		else // check 用
			ft_dprintf(fd_log,
					">> don't call recursive sort_quick func -- top side\n");
	}
}

void	recursive_bottom_side(t_stack *stack_a, t_stack *stack_b,
			t_range range, int original_low)
{
	range.low = original_low;
	if (is_sorted_range(stack_a, range.low, range.high) == false)
	{
		range.high = range.pi - 1;

		if (flag_debug == 1)// debug
			ft_dprintf(fd_log,
				">> call recursive sort_quick func -- bottom side\n");
				// for debug

		sort_quick(stack_a, stack_b, range);
	}
	// check用
	else
		ft_dprintf(fd_log,
			">> don't call recursive sort_quick func -- bottom side\n");
}

void	sort_quick(t_stack *src, t_stack *tmp, t_range range)
{
	int		count;
//	static t_f_is_sorted_direction	is_sorted_direction[2] = {
//				is_sorted_range, is_reverse_sorted_range};
	int		mode;
	flag_debug = 1;

	mode = (range.flag & BIT_MODE_REVERSE) > 0;
	count = 0;

	// rangeのデータ１個だけ　|| range内がソート済みなら
	// sortせず終了
	if (range.low >= range.high)
//	if (range.low >= range.high
//			|| is_sorted_direction[mode](src, range.low, range.high) == true)
		return ;

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log,
			"---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
			range.low, range.high, src->top);// for debug
		ft_dprintf(fd_log, "mode[%d]  0:normal 1:reverse\n", mode);
		debug_data(fd_log, src, tmp);// for debug
		ft_dprintf(fd_log, ">> call partition function\n");
	}

// -----------------------------------------------------------
	// partition　high を pivot_dataとして、分割する関数
	if (mode == 0)
		partition(src, tmp, &range);
	else
		partition_reverse(src, tmp, &range);
// -----------------------------------------------------------

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log, ">> after partition func\n");
		debug_data(fd_log, src, tmp);
	}


	if (flag_debug == 1)//debug
		ft_dprintf(fd_log,
				">> is_reverse_sorted_range = [%d] false[%d] true[%d]\n",
				is_reverse_sorted_range(tmp, range.low, range.high),
				false, true);

//	if (mode == 1)
//	{
//		ft_dprintf(fd_log, "exit\n");
//		exit(0);
//	}

		// mode == 0 の時??
			if (is_reverse_sorted_range(src, range.low, range.high) == false && mode == 1)
				recursive_top_side(src, tmp, range);
			else if (is_sorted_range(src, range.low, range.high) == false && mode == 0)
				recursive_top_side(src, tmp, range);
			else
				return ;
//			if (is_sorted_range(src, , range.high) == false)
//				recursive_bottom_side(src, tmp, range, original_low);
//		}


// -----------------  top側のデータを戻す
//	while (count > 0)
//	{
//		instruct_px(src, tmp);
//		count--;
//	}

	if (flag_debug == 1)//debug
		ft_dprintf(fd_log,
			"---- end time ---- range low[%d] ~ high[%d] ... src->top[%d]\n",
			range.low, range.high, src->top);
}
