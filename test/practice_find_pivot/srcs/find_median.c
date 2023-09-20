/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:02:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/20 18:56:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (used for sorting)
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void	print_arr(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	printf("\n");
}
// Function to find the median value from an array of integers
int findMedian(int arr[], int size)
{
	printf("---- before ----\n");
	print_arr(arr, size);
    // Sort the array in ascending order
    //qsort(arr, size, sizeof(int), compare);
    ft_qsort(arr, 0, size - 1);
	printf("---- after ----\n");
	print_arr(arr, size);

	printf("arr[size / 2] = %d\n", arr[size/2]);

    // Calculate the median
    if (size % 2 == 0) {
        // If the number of elements is even, average the middle two elements
        int mid1 = arr[(size - 1) / 2];
        int mid2 = arr[size / 2];
        return (int)(mid1 + mid2) / 2.0;
    } else {
        // If the number of elements is odd, return the middle element
        return (int)arr[size / 2];
    }
}

int main() {
    //int arr[] = {4, 2, 7, 1, 9, 6};
    int arr[] = {8, -25, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int median = findMedian(arr, size);

    printf("Median value: %d\n", median);

    return 0;
}
