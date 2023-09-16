/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:50:09 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/16 17:59:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"

void	sort_two_elements(t_stack *stack, int mode)
{
	static t_f_is_compare_than	is_compare_direction[2] = {
		is_less_than, is_more_than};

	if (is_compare_direction[mode](
			stack->data[0], stack->data[stack->top]) == true)
		instruct_sx(stack);
}
