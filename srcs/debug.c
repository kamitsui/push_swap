/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 09:02:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "ft_printf.h"


void	debug_data(t_stack *left, t_stack *right)
{
	int	left_top = left->top;
	int	right_top = right->top;

	ft_printf("\x1B[100m\x1B[37m");
	while ((left_top >= 0) || (right_top >= 0))
	{
		if (left_top < 0)
			ft_printf("  ");
		else
			ft_printf("%d ", left->data[left_top]);
		if (right_top < 0)
			ft_printf("\n");
		else
			ft_printf("%d\n", right->data[right_top]);
		left_top -= 1;
		right_top -= 1;
	}
	ft_printf(ONE_LINE);
	ft_printf("%s %s", left->name, right->name);
	ft_printf("\x1B[0m\n");
}

void	repeat_push(t_stack *dst, t_stack *src, int num)
{
	int	i;

	ft_printf("\x1B[100m\x1B[37m");
	ft_printf(ONE_LINE);
	ft_printf("Exec");
	i = 0;
	while (i < num)
	{
		ft_printf(" %s%s", "p", dst->name);
		i++;
	}
	ft_printf("\x1B[0m\n");
	i = 0;
	while (i < num)
	{
		push_data(dst, src);
		i++;
	}
}

void	repeat_swap(t_stack *target, int num)
{
	int	i;

	ft_printf("\x1B[100m\x1B[37m");
	ft_printf("Exec");
	i = 0;
	while (i < num)
	{
		ft_printf(" s%s", target->name);
		i++;
	}
	ft_printf("\x1B[0m\n");
	i = 0;
	while (i < num)
	{
		swap_one(target);
		i++;
	}
}

void	repeat_swap_same(t_stack *target1, t_stack *target2, int num)
{
	int	i;

	ft_printf("\x1B[100m\x1B[37m");
	ft_printf("Exec");
	i = 0;
	while (i < num)
	{
		ft_printf(" ss");
		i++;
	}
	ft_printf("\x1B[0m\n");
	i = 0;
	while (i < num)
	{
		swap_two(target1, target2);
		i++;
	}
}

void	repeat_rotate(t_stack *target, int num)
{
	int	i;

	ft_printf("\x1B[100m\x1B[37m");
	ft_printf("Exec");
	i = 0;
	while (i < num)
	{
		ft_printf(" r%s", target->name);
		i++;
	}
	ft_printf("\x1B[0m\n");
	i = 0;
	while (i < num)
	{
		rotate_one(target);
		i++;
	}
}

void	repeat_rotate_same(t_stack *target1, t_stack *target2, int num)
{
	int	i;

	ft_printf("\x1B[100m\x1B[37m");
	ft_printf("Exec");
	i = 0;
	while (i < num)
	{
		ft_printf(" rr");
		i++;
	}
	ft_printf("\x1B[0m\n");
	i = 0;
	while (i < num)
	{
		rotate_two(target1, target2);
		i++;
	}
}
