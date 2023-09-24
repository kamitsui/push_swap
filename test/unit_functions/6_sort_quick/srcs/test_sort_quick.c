/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_quick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 18:29:17 by kamitsui         ###   ########.fr       */
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
//	int		data_a[BUFF_SIZE];
//	int		data_b[BUFF_SIZE];
	size_t	size;
	t_range	range;
	g_fd_log = open_log("debug.log", O_TRUNC);
	//g_flag_debug = DEBUG_ON;
	g_flag_debug = DEBUG_OFF;

	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements(&argv[1]);
//	if (size > MAX_SIZE)
		allocate_data(&stack_a, &stack_b, size);
//	else
//	{
//		stack_a.data = &data_a[0];
//		stack_b.data = &data_b[0];
//	}
	set_data(&stack_a, &argv[1], size);
	stack_a.size = stack_a.top;
	stack_b.size = stack_a.size;
	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log, "--- before ---\n");
		debug_data(g_fd_log, &stack_a, &stack_b);
	}
	if (is_sorted(&stack_a) == true)
		return (0);
	range.low = 0;
	range.high = stack_a.top;
	range.mode = MODE_NORMAL;
	sort_quick(&stack_a, &stack_b, range);
	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log, "--- after ---\n");
		debug_data(g_fd_log, &stack_a, &stack_b);
		ft_dprintf(g_fd_log,
			">> is_sorted(stack_a)? [%d]  is_empty(stack_b)? [%d]\n",
			is_sorted(&stack_a), is_empty(&stack_b));
	}
	free_stack(&stack_a, &stack_b, size);
	close(g_fd_log);
	(void)argc;
	return (0);
}
