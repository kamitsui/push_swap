/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/01 17:26:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>//for printf

bool hasDuplicates(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int	*allocate_array(size_t size)
{
	// Allocate memory for an array to store the integers
	int* numbers = (int*)malloc(size * sizeof(int));
	if (!numbers)
	{
		printf("Error: Memory allocation failed.\n");
		exit (1);
	}
	return (numbers);
}

void	set_data(t_Stack *Stack, int argc, char *argv[])
{
	// Convert command-line arguments to integers and store them in the array
	for (int i = 1; i < argc; i++) {
	    Stack->data[i - 1] = atoi(argv[i]);
		Stack->top++;
		printf("data[%d]:%d\n", i-1,Stack->data[i-1]);
	}

	// Check for duplicates
	if (hasDuplicates(&Stack->data[0], argc - 1))
	{
		printf("Error: Duplicate integers are not allowed.\n");
//		free(numbers);
		exit (1);
	}
}
