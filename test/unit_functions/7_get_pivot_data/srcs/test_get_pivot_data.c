/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_pivot_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 17:28:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "init.h"
#include "debug.h"
#include "sort.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// disable when review
int	g_fd_log;
int	g_flag_debug;

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		data_a[BUFF_SIZE];
	int		data_b[BUFF_SIZE];
	size_t	size;
	t_range	range;
	t_count	count;
	g_fd_log = open_log("debug.log", O_TRUNC);
	g_flag_debug = DEBUG_ON;

	size = count_elements(&argv[1]);
	init_stack(&stack_a, &stack_b, size);
	if (size > MAX_SIZE)
		allocate_data(&stack_a, &stack_b, size);
	else
	{
		stack_a.data = &data_a[0];
		stack_b.data = &data_b[0];
	}
	set_data(&stack_a, &argv[1], size);
	ft_dprintf(g_fd_log, "--- before ---\n");
	debug_data(g_fd_log, &stack_a, &stack_b);
	if (is_sorted(&stack_a) == true)
		return (0);
	range.low = 0;
	range.high = stack_a.top;
	range.mode = BOTTOM_SIDE;
	init_count(&count);
	sort_quick(&stack_a, &stack_b, range, count);
	ft_dprintf(g_fd_log, "--- after ---\n");
	debug_data(g_fd_log, &stack_a, &stack_b);
	ft_dprintf(g_fd_log,
		">> is_sorted(stack_a)? [%d]  is_empty(stack_b)? [%d]\n",
		is_sorted(&stack_a), is_empty(&stack_b));
	if (size > MAX_SIZE)
		free_stack(&stack_a, &stack_b);
	close(g_fd_log);
	(void)argc;
	return (0);
}
