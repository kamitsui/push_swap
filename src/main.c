/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/05 11:12:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"
#include <stdio.h>// for printf

// Function to initialize the stack
void init_stack(t_Stack *stack)
{
	stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(t_Stack *stack)
{
	return (stack->top == -1);
}

// Function to check if the stack is full
bool isFull(t_Stack *stack)
{
	return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(t_Stack *stack, int value)
{
	if (isFull(stack))
	{
		printf("Error: Stack is full, cannot push %d\n", value);
		return ;
	}
	stack->top++;
	stack->data[stack->top] = value;
}

// Function to pop an element from the stack
int pop(t_Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("Error: Stack is empty, cannot pop\n");
		return (-1); // Return a special value to indicate an error
	}
	int value = stack->data[stack->top];
	stack->top--;
	return (value);
}

// Function to get the top element from the stack without removing it
int peek(t_Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("Error: Stack is empty, cannot peek\n");
		return (-1); // Return a special value to indicate an error
	}
	return (stack->data[stack->top]);
}

int main(int argc, char* argv[]) {
	t_Stack Stack_a;
	t_Stack Stack_b;

	// Check if there are enough arguments (excluding the program name itself)
	if (argc < 2)
	{
		printf("Error: Not enough arguments.\n");
		return (1);
	}

	init_stack(&Stack_a);
	init_stack(&Stack_b);

//	*Stack_a.data = *allocate_array(argc - 1);
	set_data(&Stack_a, argc, argv);

	debug_data(&Stack_a, &Stack_b);
	// At this point, the input is valid, and you can proceed with further processing
	// For example, you can call the push_swap function here
	
	// Don't forget to free the dynamically allocated memory
//	free(Stack_a.data[0]);

	return (0);
}
