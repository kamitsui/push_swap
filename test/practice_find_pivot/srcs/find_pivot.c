#include <stdio.h>
#include "push_swap.h"
#include "ft_printf.h"

static int	search_min_data(int data[], int low, int high)
{
	int	min;
	int	size;
	int	i;

	min = data[low];
	size = high - low + 1;
	i = low;
	while (i < size)
	{
		ft_printf(">> data[%d] = [%d]\n", i, data[i]);
		if (min > data[i])
		{
			ft_printf(">> min[%d]\n", data[i]);
			min = data[i];
		}
		i++;
	}
	return (min);
}

static int	search_max_data(int data[], int low, int high)
{
	int	max;
	int	i;
	int	size;

	max = data[low];
	size = high - low + 1;
	i = low;
	while (i < size)
	{
		ft_printf(">> data[%d] = [%d]\n", i, data[i]);
		if (max < data[i])
		{
			ft_printf(">> max[%d]\n", data[i]);
			max = data[i];
		}
		i++;
	}
	return (max);
}

// Function to find the pivot element using the QuickSort partitioning algorithm
int findPivot(int arr[], int low, int high) {
    // Choose the last element as the pivot
    int min = search_min_data(arr, low, high);
	int max = search_max_data(arr, low, high);
	int pivot_data = (max - min) / 2 + min;

	ft_printf("min[%d] max[%d] pivot_data[%d]\n", min, max, pivot_data);
	int i = 0;
//    int i = low - 1; // Index of smaller element
//
//    for (int j = low; j <= high - 1; j++) {
//        // If the current element is smaller than or equal to the pivot
//        if (arr[j] <= pivot) {
//            // Swap arr[i] and arr[j]
//            i++;
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//        }
//    }
//
//    // Swap arr[i+1] and arr[high] (put the pivot element in its correct position)
//    int temp = arr[i + 1];
//    arr[i + 1] = arr[high];
//    arr[high] = temp;
//
    return i + 1; // Return the index of the pivot element
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pivotIndex = findPivot(arr, 0, n - 1);

    ft_printf("Pivot element: %d\n", arr[pivotIndex]);

    return 0;
}

//int findPivot(int arr[], int low, int high) {
//    // Choose the last element as the pivot
//    int pivot = arr[high];
//    int i = low - 1; // Index of smaller element
//
//    for (int j = low; j <= high - 1; j++) {
//        // If the current element is smaller than or equal to the pivot
//        if (arr[j] <= pivot) {
//            // Swap arr[i] and arr[j]
//            i++;
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//        }
//    }
//
//    // Swap arr[i+1] and arr[high] (put the pivot element in its correct position)
//    int temp = arr[i + 1];
//    arr[i + 1] = arr[high];
//    arr[high] = temp;
//
//    return i + 1; // Return the index of the pivot element
//}
