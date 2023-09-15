/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 15:37:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"
#include "ft_printf.h"

static void	set_color(int debug_fd)
{
	ft_dprintf(debug_fd, "\x1B[100m\x1B[37m");
}

static void	end_color(int debug_fd)
{
	ft_dprintf(debug_fd, "\x1B[0m\n");
}

static void	put_data(int debug_fd, t_stack *left, t_stack *right)
{
	int	left_top;
	int	right_top;

	left_top = left->top;
	right_top = right->top;
	while ((left_top >= 0) || (right_top >= 0))
	{
		if (left_top < 0)
			ft_dprintf(debug_fd, "  ");
		else
			ft_dprintf(debug_fd, "%d ", left->data[left_top]);
		if (right_top < 0)
		{
			ft_dprintf(debug_fd, "\n");
			set_color(debug_fd);
		}
		else
		{
			ft_dprintf(debug_fd, "%d\n", right->data[right_top]);
			set_color(debug_fd);
		}
		left_top -= 1;
		right_top -= 1;
	}
}

void	debug_data(int debug_fd, t_stack *left, t_stack *right)
{
	set_color(debug_fd);
	put_data(debug_fd, left, right);
	ft_dprintf(debug_fd, ONE_LINE);
	ft_dprintf(debug_fd, "\x1B[100m\x1B[37m");
	ft_dprintf(debug_fd, "%s %s", left->name, right->name);
	end_color(debug_fd);
}
