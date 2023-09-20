/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:01:26 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/19 23:04:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "sort.h"

static void	print_arr(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(void)
{
	int numbers[] = {-20, 10, 5, 2, 8, 4};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int	tmp[size];
	int	pivot;

	ft_memcpy(tmp, &numbers[0], sizeof(numbers));
	ft_printf("Before sorting:\n");
	print_arr(numbers, size);
	ft_qsort(tmp, 0, size - 1);
	ft_printf("After sorting:\n");
	print_arr(tmp, size);
	pivot = get_median(tmp, size);
	ft_printf("pivot = %d\n", pivot);
	return (0);
}
