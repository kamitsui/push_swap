/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_top_side.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:57:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "quick_sort.h"
#include <stdbool.h>

// for debug
#include "debug.h"

void	partition_top_side(t_stack *src, t_stack *tmp,
		t_range range, t_count *count)
{
	int	i;

	range.pivot_data = get_pivot_data(src, range);
	i = 0;
	while (i < range.high - range.low + 1)
	{
		set_transition(src, tmp, *count, &range);
		range.min_data = get_min_data(src, tmp, range, *count);
		if (is_more_than_stack_range(src, range.transition_low,
				range.transition_high, range.pivot_data) == false
			&& src->data[src->top] != range.pivot_data
			&& src->data[src->top] != range.min_data)
			break ;
		move_data(src, tmp, count, range);
		i++;
	}
}

// debug code
//	debug_partition_start(range.mode);
//		debug_after_transition(transition);
//		debug_current_data(src, range, transition);
