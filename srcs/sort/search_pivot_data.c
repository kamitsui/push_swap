/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pivot_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:08:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/17 20:29:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

int	search_pivot_data(t_stack *stack, t_range range)
{
	int	i;

	i = range.low;
	while (i
}
// Function to find the pivot element using the QuickSort partitioning algorithm
int findPivot(int arr[], int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high];
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (put the pivot element in its correct position)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the index of the pivot element
}
