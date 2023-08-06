/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:22:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 17:26:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

// Function to implement the insertion sort algorithm
void insert_sort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// int main() {
//     int numbers[] = {10, 5, 2, 8, 3};
//     int size = sizeof(numbers) / sizeof(numbers[0]);
// 
//     printf("Before sorting:\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", numbers[i]);
//     }
//     printf("\n");
// 
//     insertion_sort(numbers, size);
// 
//     printf("After sorting:\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", numbers[i]);
//     }
//     printf("\n");
// 
//     return 0;
// }
