/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/12 17:27:55 by kamitsui         ###   ########.fr       */
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

void	recursive_top_side(t_stack *src, t_stack *tmp,
			t_range range, int original_high)
{
				range.low = tmp->top - (original_high - range.pi - 1);
				range.high = tmp->top;
				range.flag = BIT_MODE_REVERSE;
	if (is_reverse_sorted_range(src, range.low, range.high) == false)
	{
		if (flag_debug == 1)// for debug
		{
			ft_dprintf(fd_log,
					">> call recursive sort_quick func -- top side\n");
		}
		sort_quick(tmp, src, range);
	}
	// check用
	else
		ft_dprintf(fd_log,
				">> don't call recursive sort_quick func -- top side\n");
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
	int		original_high;// いらないのでは？
	int		original_low;// いらないのでは？
	static t_f_is_sorted_direction	is_sorted_direction[2] = {
				is_sorted_range, is_reverse_sorted_range};
	int		mode;
	flag_debug = 1;

	mode = (range.flag & BIT_MODE_REVERSE) > 0;
	count = 0;
	original_high = range.high;// for debug
	original_low = range.low;

	// rangeのデータが２個未満はsortしない。|| range内がソート済みなら
	if (range.low >= range.high
			|| is_sorted_direction[mode](src, range.low, range.high) == true)
		return ;

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log,
			"---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
			range.low, range.high, src->top);// for debug
		ft_dprintf(fd_log, "mode[%d]  0:normal 1:reverse\n", mode);
		debug_data(fd_log, src, tmp);// for debug
		ft_dprintf(fd_log, ">> call partition function\n");
		ft_dprintf(fd_log, "pivot_data[%d] size[%d]=high[%d]-low[%d] top[%d]\n",
			src->data[range.high], range.high - range.low, range.high,
			range.low, src->top);
	}
	if (mode == 1)
	{
		ft_dprintf(fd_log, "exit\n");
		exit(0);
	}

// -----------------------------------------------------------
	// partition　high を pivot_dataとして、分割する関数
	range.pi = partition(src, tmp, &range);
// -----------------------------------------------------------

	if (flag_debug == 1)//debug
		ft_dprintf(fd_log, ">> after partition func -- pi[%d] pivot=[%d]\n",
			range.pi, src->data[range.pi]);// for debug
	if (flag_debug == 1)//debug
		debug_data(fd_log, src, tmp);// for debug


		// TOP側がソート済みの場合、BOTTOM側のみソートする
//		if ((range.flag & BIT_SORTED_TOP_SIDE) != 0x00)
//		{
//			range.flag = BIT_UNSORTED;// TOP側の
//			recursive_bottom_side(src, tmp, range, original_low);
//			// TOP側を戻す作業
//			while (src->top < original_high)// ？？これでいいか不安
//				instruct_px(src, tmp);
//		}

//		// 通常の再帰ソート
//		else
//		{
			if (flag_debug == 1)//debug
			ft_dprintf(fd_log,
					">> tmp->top[%d] original_high[%d] range.pi[%d]\n",
					tmp->top, original_high, range.pi);
			ft_dprintf(fd_log,
					">> is_reverse_sorted_range = [%d] true[%d] false[%d]\n",
					is_reverse_sorted_range(tmp,
						tmp->top - (original_high - range.pi - 1), tmp->top),
					true, false);
			if (is_reverse_sorted_range(tmp,
						tmp->top - (original_high - range.pi - 1), tmp->top) == false)
			{
				recursive_top_side(src, tmp, range, original_high);
				instruct_px(tmp, src);
			}
//			if (is_sorted_range(src, , range.high) == false)
//				recursive_bottom_side(src, tmp, range, original_low);
//		}

// -----------------  不要かも？？　range外のデータを戻す
		while (count > 0)
		{
			instruct_px(src, tmp);
			count--;
		}

		if (flag_debug == 1)//debug
			ft_dprintf(fd_log,
				"---- end time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				original_low, original_high, src->top);// for debug
}
