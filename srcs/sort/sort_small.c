/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:10:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/05 09:01:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	sort_small(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	if (size <= 2)
		sort_two_elements(stack_a);
	else if (size <= 3)
		sort_three_elements(stack_a);
	else
		sort_six_elements(stack_a, stack_b);
}
