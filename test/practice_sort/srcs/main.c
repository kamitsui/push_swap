/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:10:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/19 20:53:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_qsort(int arr[], int low, int high);
void	ft_insert_sort(int arr[], int size);

int main() {
    int numbers[] = {10, 5, 2, 8, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
	int	tmp[100];

	ft_memcpy(&tmp[0], &numbers[0]

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tmp[i]);
    }
    printf("\n");

    ft_qsort(tmp, 0, size - 1);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tmp[i]);
    }
    printf("\n");

    return 0;
}
//int	main(void)
//{
//	int	numbers[5];
//	int	size;
//	int	i;
//
//	set_numbers(numbers);
//	size = sizeof(numbers) / sizeof(numbers[0]);
//	printf("Before sorting:\n");
//	i = 0;
//	while (i < size)
//	{
//		printf("%d ", numbers[i]);
//		i++;
//	}
//	printf("\n");
//	insert_sort_array(numbers, size);
//	printf("After sorting:\n");
//	i = 0;
//	while (i < size)
//	{
//		printf("%d ", numbers[i]);
//		i++;
//	}
//	printf("\n");
//	return (0);
//}
