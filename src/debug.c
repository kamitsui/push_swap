/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 23:00:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>//for printf

void	debug_data(t_Stack *left, t_Stack *right)
{
	int	left_top = left->top;
	int	right_top = right->top;

	printf("%s->top:%d %s->top:%d\n",
			left->name, left_top, right->name, right_top);
	printf("----------\n");
	while ((left_top >= 0) || (right_top >= 0))
	{
		if (left_top < 0)
			printf("  ");
		else
			printf("%d ", left->data[left_top]);
		if (right_top < 0)
			printf("\n");
		else
			printf("%d\n", right->data[right_top]);
		left_top -= 1;
		right_top -= 1;
	}
	printf("----------\n");
	printf("%s %s\n", left->name, right->name);
}

void	debug_push_data(t_Stack *dst, t_Stack *src)
{
	printf("---- before ----\n");
	debug_data(src, dst);
	printf("\nInstruction\n");
	for (int i = 0; i < 3; i++)
		push_data(dst, src);
	printf("\n");
	printf("---- after ----\n");
	debug_data(src, dst);
	printf("\n");
}

void	debug_swap(t_Stack *target, t_Stack *non_target)
{
	printf("---- before ----\n");
	debug_data(target, non_target);
	printf("\nInstruction\n");
	swap(target);
	printf("\n");
	printf("---- after ----\n");
	debug_data(target, non_target);
	printf("\n");
}

void	debug_rotate(t_Stack *target1, t_Stack *target2)
{
	printf("---- before ----\n");
	debug_data(target1, target2);
	printf("\nInstruction\n");
	rotate_two(target1, target2);
//	rotate(target1);
//	rotate(target2);
	printf("\n");
	printf("---- after ----\n");
	debug_data(target1, target2);
	printf("\n");
}
