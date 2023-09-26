/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:44:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 11:55:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file allocate_data.c
 */
#include "push_swap.h"
#include "error.h"
#include <stdlib.h>

/**
 * @brief This Function to allocate memory for the data array in the heap area\n
 * if the buffer size is not sufficient.
 *
 * @param stack_a is address of stack structure.
 * @param stack_b is address of stack structure.
 * @param size is number of data to be allocated.
 */
void	allocate_data(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	stack_a->data = (int *)malloc(size * sizeof(int));
	if (stack_a->data == NULL)
		handle_error(ERR_MALLOC);
	stack_b->data = (int *)malloc(size * sizeof(int));
	if (stack_b->data == NULL)
		handle_error(ERR_MALLOC);
}
