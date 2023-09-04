/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:59:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 14:56:18 by kamitsui         ###   ########.fr       */
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
#include "ft_printf.h"// for debug

/**
 * @brief 入力されたデータに重複している値がないかチェックする関数
 *
 * @param arr[] 入力されたデータ　（コマンドライン引数）
 * @param size データの個数
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
 * @param input[] データ　（データを含む二次元配列）
 * @param size データの数
 */
void	set_data(t_stack *stack, char *input[], size_t size)
{
	int		i;
	char	*token_head;
	char	*token;

	i = 0;
	while (input[i] != NULL)
	{
		token_head = ft_strdup(input[i]);
		token = token_head;
		token = ft_strtok(token, " ");
		while (token != NULL)
		{
			stack->top++;
			if (ft_isint(token) == false)
				handle_error(ERR_NUM);
			stack->data[size - stack->top - 1] = ft_atoi(token);
			token = ft_strtok(NULL, " ");
		}
		free(token_head);
		i++;
	}
	if (has_duplicates(&stack->data[0], size) == true)
		handle_error(ERR_NUM);
}
