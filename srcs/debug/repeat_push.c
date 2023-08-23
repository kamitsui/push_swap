/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:07:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 13:42:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "debug.h"
#include "ft_printf.h"

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
