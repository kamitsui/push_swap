/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/01 17:30:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>//for printf

void	debug_data(t_Stack *a, t_Stack *b)
{
	printf("a->top:%d b->top:%d\n", a->top, b->top);
	printf("----------\n");
	while ((a->top >= 0) || (b->top >= 0))
	{
		if (a->top < 0)
			printf("  ");
		else
			printf("%d ", a->data[a->top]);
		if (b->top < 0)
			printf("\n");
		else
			printf("%d\n", b->data[b->top]);
		a->top -= 1;
		b->top -= 1;
	}
	printf("----------\n");
	printf("a b\n");
}
