/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:25:27 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/23 17:12:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"

// Only call by partition.c
void	move_min_data(t_stack *stack_a, t_stack *stack_b, t_count count)
{
	int	i;
	int	size;

	size = stack_b->top + 1 - count.less;
	i = 0;
	//while (i++ < count)// 9/23以前
	while (i++ < size)
		instruct_rrx(stack_b);
	i = 0;
	//while (i++ < count)// 9/23以前
	while (i++ < size)
	{
		instruct_px(stack_a, stack_b);
		instruct_rx(stack_a);
	}
}
