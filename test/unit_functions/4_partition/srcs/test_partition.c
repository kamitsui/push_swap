/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_partition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/05 18:43:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "init.h"
#include "debug.h"
#include "sort.h"
#include <stdlib.h>

//int	main(int argc, char *argv[])
int	main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	stack_a2;
	t_stack	stack_b2;
	t_stack	stack_a3;
	t_stack	stack_b3;
	size_t	size;
	int		pi;
	const char	*array1[10] = {"9", "8", "7", "6", "5", "4", "3", "2", "1", NULL};
	const char	*array2[9] = {"42", "3", "2", "0", "100", "59", "300", "43", NULL};
	const char	*array3[9] = {"42", "3", "2", "0", "100", "59", "300", "43", NULL};

	ft_printf("---- 9, 8, 7, 6, 5, 4, 3, 2, 1 ----\n");
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements((char **)&array1[0]);
	allocate_data(&stack_a, &stack_b, size);
	set_data(&stack_a, (char **)&array1[0], size);
	pi = 0;
	if (is_sorted(&stack_a) == false)
		pi = partition(&stack_a, &stack_b, 0, stack_a.top);
	ft_printf("pi[%d]\n", pi);
	debug_data(&stack_a, &stack_b);// for debug
	free_stack(&stack_a, &stack_b, size);

	ft_printf("---- 42, 3, 2, 0, 100, 59, 300, 43 ----\n");
	init_stack(&stack_a2, (char *)"a2");
	init_stack(&stack_b2, (char *)"b2");
	size = count_elements((char **)&array2[0]);
	allocate_data(&stack_a2, &stack_b2, size);
	set_data(&stack_a2, (char **)&array2[0], size);
	if (is_sorted(&stack_a2) == false)
		pi = partition(&stack_a2, &stack_b2, 0, stack_a2.top);
	ft_printf("pi[%d]\n", pi);
	debug_data(&stack_a2, &stack_b2);// for debug
	free_stack(&stack_a2, &stack_b2, size);

	ft_printf("---- 42, 3, 2, 0, 100, 59, 300, 43 ----\n");
	init_stack(&stack_a3, (char *)"a3");
	init_stack(&stack_b3, (char *)"b3");
	size = count_elements((char **)&array3[0]);
	allocate_data(&stack_a3, &stack_b3, size);
	set_data(&stack_a3, (char **)&array3[0], size);
	if (is_sorted(&stack_a3) == false)
		pi = partition(&stack_a3, &stack_b3, 0, stack_a3.top / 2);
	ft_printf("pi[%d]\n", pi);
	debug_data(&stack_a3, &stack_b3);// for debug
	free_stack(&stack_a3, &stack_b3, size);
	return (0);
}
