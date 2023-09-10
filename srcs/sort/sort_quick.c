/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/10 21:03:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include "debug.h"// for debug
#include "ft_printf.h"// debug
#include <stdbool.h>

#include <unistd.h>// debug
#include <fcntl.h>//debug

int	fd_log;// for debug
int	flag_debug;// for debug

void	recursive_bottom_side(t_stack *stack_a, t_stack *stack_b,
			t_range range, int temp_low)
{
	range.low = temp_low;
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

void	recursive_top_side(t_stack *stack_a, t_stack *stack_b,
			t_range range)
{
	if (is_sorted_range(stack_a, range.low, range.high) == false)
	{

		range.low = range.pi + 1;

		if (flag_debug == 1)
			ft_dprintf(fd_log,
					">> call recursive sort_quick func -- top side\n");
					// for debug

			sort_quick(stack_a, stack_b, range);
	}
	// check用
	else
		ft_dprintf(fd_log,
				">> don't call recursive sort_quick func -- top side\n");
}

void	sort_quick(t_stack *stack_a, t_stack *stack_b, t_range range)
{
	int		count;
	int		temp_high;
	flag_debug = 1;

	*range.flag_sorted = false;// 実験　run5.shがKOする要因 →　採用
	count = 0;
	temp_high = range.high;// for debug
	int		temp_low = range.low;

	// rangeに２個以上のデータがある時は、sortを行う
	if (range.low < range.high)
	{
		if (flag_debug == 1)//debug
			ft_dprintf(fd_log,
				"---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				range.low, range.high, stack_a->top);// for debug

// ---------------  不要かも？？　range外のデータを避難　（sort済み）
		while (range.high < stack_a->top)
		{
			instruct_px(stack_b, stack_a);
			count++;
		}

		if (flag_debug == 1)//debug
			ft_dprintf(fd_log, "push a -- count[%d]\n", count);// for debug
		if (flag_debug == 1)//debug
			debug_data(fd_log, stack_a, stack_b);// for debug
		if (flag_debug == 1)//debug
			ft_dprintf(fd_log, ">> call partition func -- pivot=[%d]\n",
				stack_a->data[range.high]);// for debug

		// partition　high を pivot_dataとして、分割する関数
		range.pi = partition(stack_a, stack_b, range);

		if (is_sorted_range(stack_a, range.low, range.high) == false)
		{

			if (flag_debug == 1)//debug
				ft_dprintf(fd_log, ">> after partition func -- pi[%d] pivot=[%d]\n",
					range.pi, stack_a->data[range.pi]);// for debug
			if (flag_debug == 1)//debug
				debug_data(fd_log, stack_a, stack_b);// for debug

			recursive_top_side(stack_a, stack_b, range);

			recursive_bottom_side(stack_a, stack_b, range, temp_low);

		}

// -----------------  不要かも？？　range外のデータを戻す
		while (count > 0)
		{
			instruct_px(stack_a, stack_b);
			count--;
		}

		if (flag_debug == 1)//debug
			ft_dprintf(fd_log,
				"---- end time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				temp_low, temp_high, stack_a->top);// for debug
	}
}
