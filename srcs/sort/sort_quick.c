/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 17:04:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include <stdbool.h>

// for debug
#include "debug.h"

/**
 * @brief クイックソート（再帰関数）
 *
 * @param src ソート対象のスタック
 * @param tmp ソートの際に避難させるスタック
 * @param range ソート範囲（srcスタックの要素番号）
 */
//void	sort_quick(t_stack *src, t_stack *tmp, t_range range)
void	sort_quick(t_stack *src, t_stack *tmp, t_range range, t_count count)
{
	if (range.low == range.high && range.mode == MODE_NORMAL)
		instruct_rx(src);
	if (range.low < range.high
		|| is_sorted_range(src, range.low, range.high) == false)
	{
		if (range.mode == 0)
			partition(src, tmp, range, &count);
		else
			partition_reverse(src, tmp, range, &count);
		recursive_top_side(src, tmp, range, count);
		recursive_bottom_side(src, tmp, range, count);
	}
	end_process(src, tmp, range);
}

//この関数で使う debug functions ( exist in debug_sort_quick.c )
//	debug_sort_quick_start(src, tmp, range);
//		debug_after_partition(src, tmp, range);
//		debug_after_recursive_top_side(src, tmp, range);
//		debug_after_recursive_bottom_side(src, tmp, range);
//	debug_sort_quick_end(src, tmp, range);
