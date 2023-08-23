/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:08:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 13:43:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

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
