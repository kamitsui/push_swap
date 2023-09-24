/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:29 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 18:44:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

//void	free_stack(t_stack *stack_a, t_stack *stack_b, size_t size)
void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
//	if (size > MAX_SIZE)
//	{
		free(stack_a->data);
		free(stack_b->data);
//		(void)size;// 9/24仮
//	}
}
