/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:29 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 12:19:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// データ個数がMAX_SIZE以上の時、フリーする
void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->data);
	free(stack_b->data);
}
