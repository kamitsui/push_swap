/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:08:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/20 22:36:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

// debug
#include "debug.h"
#include "ft_printf.h"

int	g_fd_log;
int	g_flag_debug;

static int	*allocate_array(int	size)
{
	int	*array_pointer;

	array_pointer = (int *)malloc(sizeof(int) * size);
	if (array_pointer == NULL)
		handle_error(ERR_MALLOC);
	return (array_pointer);
}

// デバッグ用の関数
//static void	debug_array(int arr[], int size)
//{
//	int	i;
//
//	i = 0;
//	while (i < size)
//	{
//		if (g_flag_debug == DEBUG_ON)
//			ft_dprintf(g_fd_log, "arr[%d] = %d\n", i, arr[i]);
//		i++;
//	}
//	if (g_flag_debug == DEBUG_ON)
//		ft_dprintf(g_fd_log, "\n");
//}

//int	get_median(int arr[], int size)
//{
//	int	mid1;
//	int	mid2;
//
//	if (size % 2 == 0)
//	{
//		mid1 = arr[(size - 1) / 2];
//		mid2 = arr[size / 2];
//		return ((double)(mid1 + mid2) / 2.0);
//	}
//	else
//		return ((double)arr[size / 2]);
//}

// Function to find the median value from an array of integers
int	get_pivot_data(t_stack *stack, t_range range)
{
	int	size;
	int	arr_stack[MAX_SIZE];
	int	*arr;

	size = range.high - range.low + 1;
	//arr = init_array(stack, range, &arr_stack);
	if (size > MAX_SIZE)
		arr = allocate_array(size);
	else
		arr = &arr_stack[0];
	ft_memcpy(arr, &stack->data[range.low], size * sizeof(int));
	ft_qsort(arr, 0, size - 1);
	// return (get_median(arr, size));
	if (size % 2 == 0)
	{
		int mid1 = arr[(size - 1) / 2];
		int mid2 = arr[size / 2];
		if (size > MAX_SIZE)
			free(arr);
		return ((int)((mid1 + mid2) / 2.0));
	}
	else
	{
		if (size > MAX_SIZE)
			free(arr);
		return ((int)arr[size / 2]);
	}
}
//debug code
// ソート前の配列デバッグ
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log,
//			">> call get_pivot_data function low[%d]~high[%d] size[%d]\n",
//			range.low, range.high, size);
//		ft_dprintf(g_fd_log, "---- before ----\n");
//		debug_array(&stack->data[range.low], size);
//	}
// ソート後の配列デバッグ
//	if (g_flag_debug == DEBUG_ON)
//	{
//		ft_dprintf(g_fd_log, "---- after ----\n");
//		debug_array(arr, size);
//		ft_dprintf(g_fd_log, "---- midean ----\n");
//		ft_dprintf(g_fd_log, "size / 2 = %d  arr[%d] = [%d]\n",
//			size/2, size/2, arr[size/2]);
//	}
// リターン値 median, mid1, mid2を出力 （配列要素数が偶数の時）
//		if (g_flag_debug == DEBUG_ON)
//		{
//			ft_dprintf(g_fd_log, "mid1[%d] mid2[%d]\n", mid1, mid2);
//			ft_dprintf(g_fd_log, "median [%d]\n",
//					(int)((mid1 + mid2) / 2.0));
//		}
// リターン値　medianを出力 (配列要素数が奇数の時）
//		if (g_flag_debug == DEBUG_ON)
//			ft_dprintf(g_fd_log, "median [%d]\n", arr[size/2]);
