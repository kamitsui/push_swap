/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:50:09 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 20:50:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"

void	sort_two_elements(t_stack *stack_a)
{
	if (is_less_than(stack_a->data[0], stack_a->data[stack_a->top]) == true)
		instruct_sx(stack_a);
}
