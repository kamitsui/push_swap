/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_large_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:30:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 18:56:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "instruct.h"

// for debug
#include "debug.h"
#include "ft_printf.h"

// 大きい値を元に戻す作業 (stack_a のTOPに戻す） bottom側のみ
void	move_large_data(t_stack *src, t_count count)
{
	int	i;

	if (count.over - 1 != src->top)
	{
		i = 0;
		if (src->top / 2 < count.over)
		{
			while (i < src->top + 1 - count.over)
			{
				instruct_rx(src);
				i++;
			}
		}
		else
		{
			while (i < count.over)
			{
				instruct_rrx(src);
				i++;
			}
		}
	}
}
// debug code
//			debug_number_of_ra(src, count);
//			debug_number_of_rra(count);
//				debug_move_data(src);
