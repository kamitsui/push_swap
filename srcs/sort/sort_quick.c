/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/09 22:11:15 by kamitsui         ###   ########.fr       */
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
//			t_range range)
			t_range range, int temp_low)
{
	range.low = temp_low;
	range.high = range.pi - 1;
	if (flag_debug == 1)
		ft_dprintf(fd_log,
			">> call recursive sort_quick func -- bottom side\n");
			// for debug
	sort_quick(stack_a, stack_b, range);
}

void	recursive_top_side(t_stack *stack_a, t_stack *stack_b,
			t_range range)
//			t_range range, int temp_high)
{
	if (*range.flag_sorted == false)
	{
		range.low = range.pi + 1;
		//range.high = temp_high;
	if (flag_debug == 1)
		ft_dprintf(fd_log,
				">> call recursive sort_quick func -- top side\n");
				// for debug
		sort_quick(stack_a, stack_b, range);
	}
}

//void	sort_quick(t_stack *stack_a, t_stack *stack_b, int low, int high)
void	sort_quick(t_stack *stack_a, t_stack *stack_b, t_range range)
{
	int		count;
	int		temp_high;
//	bool	flag_sorted;
//	int		partition_index;
	flag_debug = 1;

	*range.flag_sorted = false;// 実験　run5.shがKOする要因 →　採用
	if (is_sorted_range(stack_a, range.low, range.high) == true)
		//range.flag_sorted = true;
		return ;
	count = 0;
	temp_high = range.high;// for debug
	int		temp_low = range.low;
	if (range.low < range.high)
	{
	if (flag_debug == 1)//debug
		ft_dprintf(fd_log,
				"---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				range.low, range.high, stack_a->top);// for debug
		//debug_data(fd_log, stack_a, stack_b);// for debug
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
		range.pi = partition(stack_a, stack_b, range);
		if (*range.flag_sorted == false)
		{

		if (flag_debug == 1)//debug
		ft_dprintf(fd_log, ">> after partition func -- pi[%d] pivot=[%d]\n",
				range.pi, stack_a->data[range.pi]);// for debug
		if (flag_debug == 1)//debug
			debug_data(fd_log, stack_a, stack_b);// for debug

		recursive_top_side(stack_a, stack_b, range);
		// is_sorted_range だったら。。。　手数減らせるかも？？？
		recursive_bottom_side(stack_a, stack_b, range, temp_low);

		}

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
