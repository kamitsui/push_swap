/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 17:54:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>//for printf

void	debug_data(t_Stack *a, t_Stack *b)
{
	int	a_top = a->top;
	int	b_top = b->top;

	printf("a->top:%d b->top:%d\n", a_top, b_top);
	printf("----------\n");
	while ((a_top >= 0) || (b_top >= 0))
	{
		if (a_top < 0)
			printf("  ");
		else
			printf("%d ", a->data[a_top]);
		if (b_top < 0)
			printf("\n");
		else
			printf("%d\n", b->data[b_top]);
		a_top -= 1;
		b_top -= 1;
	}
	printf("----------\n");
	printf("a b\n");
}
