/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/01 15:43:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	*init_data(int argc, char *argv[])
{
	// Allocate memory for an array to store the integers
	int* numbers = (int*)malloc((argc - 1) * sizeof(int));
	if (!numbers)
	{
		printf("Error: Memory allocation failed.\n");
		exit (1);
	}

	// Convert command-line arguments to integers and store them in the array
	for (int i = 1; i < argc; i++) {
	    numbers[i - 1] = atoi(argv[i]);
	}

	// Check for duplicates
	if (hasDuplicates(numbers, argc - 1))
	{
		printf("Error: Duplicate integers are not allowed.\n");
		free(numbers);
		exit (1);
	}
}
