/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:04:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 09:02:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>

#define MAX_SIZE 100

/**
 * @brief スタックのデータ構造 { int型の配列, 配列要素の先頭, スタック名前 }
 */
typedef struct s_stack
{
	int		data[MAX_SIZE];
	int		top;
	char	*name;
}	t_stack;

/**
 * @brief スタックの初期化で使う関数
 */
void init_stack(t_stack *stack, char *name);
int		*allocate_array(size_t size);
void	set_data(t_stack *stack, int argc, char *argv[]);

/**
 * @brief スタックを調べる関数 ( stack_utils.c )
 */
bool	isEmpty(t_stack *stack);
bool	isFull(t_stack *stack);

/**
 * @brief 命令の関数 ( instructions.c )
 */
void	push_data(t_stack *dst, t_stack *src);
void	swap_one(t_stack *target);
void	swap_two(t_stack *target1, t_stack *target2);
void	rotate_one(t_stack *target);
void	rotate_two(t_stack *target1, t_stack *target2);

/**
 * @brief スタック操作に関する関数（ operation.c ）
 */
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		peek(t_stack *stack);


// learning sort function
void	insert_sort(int arr[], int size);

#endif
