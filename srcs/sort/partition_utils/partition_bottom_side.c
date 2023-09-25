/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_bottom_side.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 21:51:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

// for debug
#include "debug.h"

void	partition_bottom_side(t_stack *src, t_stack *tmp,
		t_range range, t_count *count)
{
	int				i;

	range.pivot_data = get_pivot_data(src, range);
	i = 0;
	while (i < range.high - range.low + 1)
	{
		set_transition(src, tmp, *count, &range);
		range.min_data = get_min_data(src, tmp, range, *count);
		if (is_less_than_stack_range(src, range.transition_low,
				range.transition_high, range.pivot_data + 1) == false
			&& src->data[src->top] != range.pivot_data
			&& src->data[src->top] != range.min_data)
			break ;
		move_data(src, tmp, count, range);
		i++;
	}
	move_large_data(src, *count);
	if (count->over > 0)
		move_min_data(src, tmp, *count);
	count->over += range.high - range.low + 1 - i;
}

// debug code
//	debug_partition_start(range.mode);
//		debug_after_transition(transition);
//		debug_current_data(src, range, transition);

//補足説明
//	count->over += range.high - range.low + 1 - i;
//	move_large_dataのrra回数を合わせるため、
//	かつ、recursive_bottom_sideのrange.lowをセットするために補填
