/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 10:51:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include "debug.h"// debug

int main(int argc, char* argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments.\n");
		return (1);
	}
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	if (argc > MAX_SIZE)
	{
		*stack_a.data = *allocate_array(argc - 1);
		*stack_b.data = *allocate_array(argc - 1);
	}
	set_data(&stack_a, argc, argv);
	debug_data(&stack_a, &stack_b);
// Test Instruction : sa
	repeat_swap(&stack_a, 1);
	debug_data(&stack_a, &stack_b);
// Test Instruction : pb pb pb
	repeat_push(&stack_b, &stack_a, 3);
	debug_data(&stack_a, &stack_b);

//// Test Instruction : ra + rb
//	repeat_rotate(&stack_a, 1);
//	repeat_rotate(&stack_b, 1);
//	debug_data(&stack_a, &stack_b);
//// Test Instruction : sa + sb
//	repeat_swap(&stack_a, 1);
//	repeat_swap(&stack_b, 1);
//	debug_data(&stack_a, &stack_b);

// Test Instruction : rr ( ra + rb )
	repeat_rotate_same(&stack_a, &stack_b, 1);
	debug_data(&stack_a, &stack_b);
// Test Instruction : ss
	repeat_swap_same(&stack_a, &stack_b, 1);
	debug_data(&stack_a, &stack_b);


	// At this point, the input is valid, and you can proceed with further processing
	// For example, you can call the push_swap function here
	// insert_sort(stack_a.data, stack_a.top + 1);// for array
	// insert_sort(&stack_a, &stack_b);
	if (argc > MAX_SIZE)
	{
		free(stack_a.data);
		free(stack_b.data);
	}
	// Don't forget to free the dynamically allocated memory
	system("leaks push_swap");
	return (0);
}
