/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:25:27 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/22 16:00:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"

// Only call by partition.c
void	move_min_data(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		instruct_rrx(stack_b);
	i = 0;
	while (i++ < count)
	{
		instruct_px(stack_a, stack_b);
		instruct_rx(stack_a);
	}
}
