/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:04:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/06 22:25:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>

/**
 * @brief スタックのデータ構造 { int型の配列, 配列要素の先頭, スタック名前 }
 */
#define MAX_SIZE 100
typedef struct s_Stack
{
	int		data[MAX_SIZE];
	int		top;
	char	*name;
}	t_Stack;

/**
 * @brief スタックの初期化で使う関数
 */
int		*allocate_array(size_t size);
void	set_data(t_Stack *Stack, int argc, char *argv[]);

/**
 * @brief スタックを調べる関数 ( stack_utils.c )
 */
bool	isEmpty(t_Stack *stack);
bool	isFull(t_Stack *stack);

/**
 * @brief 命令の関数 ( instructions.c )
 */
void	push_data(t_Stack *dst, t_Stack *src);
void	swap(t_Stack *stack);
void	rotate(t_Stack *stack);

/**
 * @brief スタック操作に関する関数（ operation.c ）
 */
void	push(t_Stack *stack, int value);
int		pop(t_Stack *stack);
int		peek(t_Stack *stack);


// learning sort function
void	insert_sort(int arr[], int size);

/**
 * @brief スタックのデータを表示する関数
 */
void	debug_data(t_Stack *a, t_Stack *b);
void	debug_push_data(t_Stack *dst, t_Stack *src);
void	debug_swap(t_Stack *target, t_Stack *non_target);

#endif
