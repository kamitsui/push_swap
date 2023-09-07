/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/07 19:07:16 by kamitsui         ###   ########.fr       */
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

//void	sort_quick(t_stack *stack_a, t_stack *stack_b, int low, int high)
void	sort_quick(t_stack *stack_a, t_stack *stack_b, t_range range)
{
	size_t	count;
	int		temp_high;
	bool	flag_sorted;
	int		partition_index;

	count = 0;
	temp_high = range.high;
	int		temp_low = range.low;//for debug
	flag_sorted = false;
	if (range.low < range.high)
	{
		ft_dprintf(fd_log, "---- one time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				range.low, range.high, stack_a->top);// for debug
		debug_data(fd_log, stack_a, stack_b);// for debug
		while (range.high < stack_a->top)
		{
			instruct_px(stack_b, stack_a);
			count++;
		}
		ft_dprintf(fd_log, "push a -- count[%d]\n", count);// for debug
		debug_data(fd_log, stack_a, stack_b);// for debug
		ft_dprintf(fd_log, ">> call partition func -- pivot=[%d]\n",
				stack_a->data[range.high]);// for debug
		partition_index = partition(stack_a, stack_b, range, &flag_sorted);
		ft_dprintf(fd_log, ">> after partition func -- pi[%d] pivot=[%d]\n",
				partition_index, stack_a->data[partition_index]);// for debug
		debug_data(fd_log, stack_a, stack_b);// for debug
		range.high = partition_index - 1;
		ft_dprintf(fd_log, ">> call recursive sort_quick func -- bottom side\n");// for debug
		sort_quick(stack_a, stack_b, range);
		if (flag_sorted == false)
		{
			range.low = partition_index + 1;
			range.high = temp_high;
			ft_dprintf(fd_log, ">> call recursive sort_quick func -- top side\n");// for debug
			sort_quick(stack_a, stack_b, range);
		}
		while (count > 0)
		{
			instruct_px(stack_a, stack_b);
			count--;
		}
		ft_dprintf(fd_log, "---- end time ---- range low[%d] ~ high[%d] ... top[%d]\n",
				temp_low, temp_high, stack_a->top);// for debug
	}
}
