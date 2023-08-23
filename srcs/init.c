/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 13:58:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"
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
void	init_stack(t_stack *stack, char *name)
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
static bool	has_duplicates(int arr[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
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
	int	i;

	i = 1;
	while (i < argc)
	{
		stack->data[i - 1] = ft_atoi(argv[argc - i]);
		stack->top++;
		i++;
	}
	if (has_duplicates(&stack->data[0], argc - 1))
	{
		ft_printf(MSG_ERR_SETDATA);
		exit (1);
	}
}
//debug code
//		ft_printf("data[%d]:%d\n", i-1,stack->data[i-1]);

/**
 * @brief 不足分のスタックデータをヒープ領域に確保する関数
 *
 * @param size 不足分のデータ数
 *
 * @return ヒープ領域に確保したデータのアドレス
 */
int	*allocate_array(size_t size)
{
	int	*numbers;

	numbers = (int *)malloc(size * sizeof(int));
	if (!numbers)
	{
		ft_printf(MSG_ERR_MALLOC);
		exit (1);
	}
	return (numbers);
}
