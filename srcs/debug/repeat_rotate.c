/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:09:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 17:17:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

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
		instruct_rx(target);
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
		instruct_rr(target, target2);
		i++;
	}
}
