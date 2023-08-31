/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:22:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 21:19:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

// Function to implement the insertion sort algorithm
static void	insert_sort_array(int arr[], int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	set_numbers(int numbers[])
{
	numbers[0] = 10;
	numbers[1] = 5;
	numbers[2] = 2;
	numbers[3] = 8;
	numbers[4] = 3;
}

int	main(void)
{
	int	numbers[5];
	int	size;
	int	i;

	set_numbers(numbers);
	size = sizeof(numbers) / sizeof(numbers[0]);
	printf("Before sorting:\n");
	i = 0;
	while (i < size)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");
	insert_sort_array(numbers, size);
	printf("After sorting:\n");
	i = 0;
	while (i < size)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");
	return (0);
}
