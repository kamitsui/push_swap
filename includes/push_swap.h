/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:04:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/14 18:56:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>

/**
 * @brief スタック領域のデータ配列サイズ
 */
# define MAX_SIZE	100

/**
 * @brief 文字列のバッファサイズ（count_number_data.cで使用）
 */
# define BUFF_SIZE	1024

/**
 * @brief スタックのデータ構造 { int型の配列, 配列要素の先頭, スタック名前 }
 * @details
 * data : int型のデータ配列のポインタ\n
 * top : スタックデータの要素数\n
 * name : スタックの名前\n
 */
typedef struct s_stack
{
	int		*data;
	int		top;
	char	*name;
}	t_stack;

/**
 * @brief スタックの容量が空かどうか調べる。
 */
bool	is_empty(t_stack *stack);

/**
 * @brief スタックの容量がBUFF_SIZEかどうか調べる。
 */
bool	is_full(t_stack *stack);

/**
 * @brief スタックの整数がすでに昇順か否か調べる関数
 */
bool	is_sorted(t_stack *stack);

/**
 * @brief スタックの整数がすでに昇順か否か調べる関数(範囲指定バージョン)
 */
bool	is_sorted_range(t_stack *stack, int low, int high);

bool	is_reverse_sorted_range(t_stack *stack, int low, int high);

typedef bool	(*t_f_is_sorted_direction)(t_stack *, int, int);

/**
 * @brief Check if a is less than b
 */
bool	is_less_than(int a, int b);

/**
 * @brief Check if a is more than b
 */
bool	is_more_than(int a, int b);

/**
 * @brief Check if the array's data in the range on stack is less than value
 */
bool	is_less_than_stack_range(t_stack *stack,
		int low, int high, int pivot_data);

bool	is_more_than_stack_range(t_stack *stack,
		int low, int high, int pivot_data);
/**
 * @brief スタックに値をプッシュする（先頭要素に値を入れる）
 */
void	push(t_stack *stack, int value);

/**
 * @brief スタックからdata[top]の値をポップする（取り出す＋削除）
 */
int		pop(t_stack *stack);

/**
 * @brief スタックから先頭要素(data[top])を削除せずに値を取り出す。
 */
int		peek(t_stack *stack);

void	free_stack(t_stack *stack_a, t_stack *stack_b, size_t size);

#endif
