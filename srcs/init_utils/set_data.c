/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:59:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 11:04:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_data.c
 * @brief コマンドライン引数のデータをスタック構造体に格納する関数
 */
#include "push_swap.h"
#include "error.h"
#include "libft.h"
#include <stdbool.h>

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
	if (has_duplicates(&stack->data[0], argc - 1) == true)
		handle_error(ERR_NUM);
}
