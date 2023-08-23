/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 09:03:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

// Function to initialize the stack
/**
 * @brief スタックの初期化
 *
 * @param stack type(t_stack *) スタック構造体のポインタ
 */
void init_stack(t_stack *stack, char *name)
{
	stack->top = -1;
	stack->name = name;
}

/**
 * @brief 入力されたデータに重複している値がないかチェックする関数
 *
 * @param arr[] 入力されたデータ　（コマンドライン引数）
 * @param size データの個数　（コマンドライン引数の数ー１）
 *
 * @return true(0) or false(1)
 */
static bool hasDuplicates(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
				return (true);
		}
	}
	return false;
}

/**
 * @brief コマンドライン引数のデータをスタック構造体に格納する関数
 *
 * @param stack 格納先のスタック構造体
 * @param argc データの数＋１　（コマンドライン引数の数）
 * @param argv[] データ　（コマンドライン引数）
 */
void	set_data(t_stack *stack, int argc, char *argv[])
{
	// Convert command-line arguments to integers and store them in the array
	for (int i = 1; i < argc; i++)
	{
		stack->data[i - 1] = ft_atoi(argv[argc - i]);
		stack->top++;
//		ft_printf("data[%d]:%d\n", i-1,stack->data[i-1]);
	}

	// Check for duplicates
	if (hasDuplicates(&stack->data[0], argc - 1))
	{
		ft_printf("Error: Duplicate integers are not allowed.\n");
		exit (1);
	}
}

/**
 * @brief 不足分のスタックデータをヒープ領域に確保する関数
 *
 * @param size 不足分のデータ数
 *
 * @return ヒープ領域に確保したデータのアドレス
 */
int	*allocate_array(size_t size)
{
	// Allocate memory for an array to store the integers
	int* numbers = (int*)malloc(size * sizeof(int));
	if (!numbers)
	{
		ft_printf("Error: Memory allocation failed.\n");
		exit (1);
	}
	return (numbers);
}
