/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:50:09 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 17:06:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include <stdbool.h>

void	sort_two_elements(t_stack *stack)
{
	if (is_less_than(stack->data[0], stack->data[stack->top]) == true)
		instruct_sx(stack);
}
