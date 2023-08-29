/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:57:10 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 17:54:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include <stdlib.h>
#include "push_swap.h"

/**
 * @brief count number of elements data
 */
size_t	count_elements(char *input[]);

/**
 * @brief スタックの初期化
 */
void	init_stack(t_stack *stack, char *name);

/**
 * @brief 不足分のスタックデータをヒープ領域に確保する関数
 */
void	allocate_data(t_stack *stack_a, t_stack *stack_b, size_t size);

/**
 * @brief コマンドライン引数のデータをスタック構造体に格納する関数
 */
void	set_data(t_stack *stack, char *input[], size_t size);

#endif
