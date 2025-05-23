/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:22:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/19 22:08:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// Function to implement the insertion sort algorithm
static void	ft_insert_sort(int arr[], int size)
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

static void	print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ft_printf("%d ", arr[i]);
	}
	ft_printf("\n");
}

int main(void)
{
	int numbers[] = {10, 5, 2, 8, 3};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int	tmp[size];

	ft_memcpy(tmp, &numbers[0], sizeof(numbers));
	ft_printf("Before sorting:\n");
	print_arr(numbers, size);
	ft_insert_sort(tmp, size);
	ft_printf("After sorting:\n");
	print_arr(tmp, size);
	return (0);
}
