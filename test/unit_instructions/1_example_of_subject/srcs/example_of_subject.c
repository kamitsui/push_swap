/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_of_subject.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/07 17:03:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "init.h"
#include "debug.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

void	go_example(t_stack *stack_a, t_stack *stack_b)
{
	repeat_swap(stack_a, 1);
	debug_data(STDOUT_FILENO, stack_a, stack_b);
	repeat_push(stack_b, stack_a, 3);
	debug_data(STDOUT_FILENO, stack_a, stack_b);
	repeat_rotate_same(stack_a, stack_b, 1);
	debug_data(STDOUT_FILENO, stack_a, stack_b);
	repeat_reverse_rotate_same(stack_a, stack_b, 1);
	debug_data(STDOUT_FILENO, stack_a, stack_b);
}
//// Test Instruction : ss
//	repeat_swap_same(stack_a, stack_b, 1);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);
//
//// Test Instruction : ra + rb
//	repeat_rotate(stack_a, 1);
//	repeat_rotate(stack_b, 1);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);
//// Test Instruction : sa + sb
//	repeat_swap(stack_a, 1);
//	repeat_swap(stack_b, 1);
//	debug_data(STDOUT_FILENO, stack_a, stack_b);
//
//// Test Instruction : rrr ( rra + rrb )
//	repeat_reverse_rotate(stack_a, 1);
//	repeat_reverse_rotate(stack_b, 1);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	size_t	size;

	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments.\n");
		return (1);
	}
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements(&argv[1]);
	allocate_data(&stack_a, &stack_b, size);
	set_data(&stack_a, &argv[1], size);
	debug_data(STDOUT_FILENO, &stack_a, &stack_b);
	go_example(&stack_a, &stack_b);
	free(stack_a.data);
	free(stack_b.data);
	system("leaks push_swap");
	return (0);
}
