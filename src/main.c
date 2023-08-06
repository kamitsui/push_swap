/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 22:27:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <stdio.h>// for printf

// Function to initialize the stack
/**
 * @brief スタックの初期化
 *
 * @param stack type(t_Stack *) スタック構造体のポインタ
 */
static void init_stack(t_Stack *stack, char *name)
{
	stack->top = -1;
	stack->name = name;
}

int main(int argc, char* argv[])
{
	t_Stack	Stack_a;
	t_Stack	Stack_b;

	// Check if there are enough arguments (excluding the program name itself)
	if (argc < 2)
	{
		printf("Error: Not enough arguments.\n");
		return (1);
	}

	init_stack(&Stack_a, (char *)"a");
	init_stack(&Stack_b, (char *)"b");

//	*Stack_a.data = *allocate_array(argc - 1);
	set_data(&Stack_a, argc, argv);

// Test Instruction : sa
	debug_swap(&Stack_a, &Stack_b);
// Test Instruction : pb pb pb
	debug_push_data(&Stack_b, &Stack_a);

	// At this point, the input is valid, and you can proceed with further processing
	// For example, you can call the push_swap function here
//	insert_sort(Stack_a.data, Stack_a.top + 1);// for array
	//insert_sort(&Stack_a, &Stack_b);

	
	// Don't forget to free the dynamically allocated memory
	system("leaks push_swap");

	return (0);
}
