/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/12 13:13:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "sort.h"
#include "debug.h"// for debug
#include "ft_printf.h"// debug
#include <stdbool.h>

int	fd_log;// for debug
int	flag_debug;//debug

int	partition(t_stack *stack_a, t_stack *stack_b, t_range *range)
{
	int	pivot_data;
	int	size;
	int	i;
	int	count_over;
	int	count_less;
	flag_debug = 1;

	pivot_data = stack_a->data[range->high];
	size = range->high - range->low;

	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "pivot_data[%d] size[%d]=high[%d]-low[%d] top[%d]\n",
			pivot_data, size, range->high, range->low, stack_a->top);

	// ----------------   ?? 不要になるかも　保留 -----------------
	// pivot_dataまで（range外のデータ）をstack_bに避難させる
	while (range->high < stack_a->top)
		instruct_px(stack_b, stack_a);

	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "[%d]pivot_data\n", pivot_data);

	// is_less_than_in_stack_range
	// ピボットの値未満しかなければ、以下の処理をせず、range->highを返す
	// 期待効果は、無駄な命令が減る。
	if (flag_debug == 1)// debug
		ft_dprintf(fd_log, "[%d] is_less_than_range_stack(..., pivot_data[%d])\n",
			is_less_than_range_stack(stack_a, range->low, range->high, pivot_data), pivot_data);

	// -----------------  改良？？　size x pb をして、flag_sorted = true にすべきか？
	// 　余計な pa, pb をなくすため。
	// 機能：pivot_dataが一番大きい値なら、ソート不要　highをそのままpiとして返す
	if (is_less_than_range_stack(stack_a, range->low, range->high, pivot_data) == false)
		return (range->high);

	// range内のデータが逆順だったら、逆sortをさせる。
	// この条件だめかも？？　bottom側のデータも見てしまっているため? 保留
	if (is_reverse_sorted_range(stack_a, range->low, range->high) == true)
	{
		if (flag_debug == 1)// for debug
			ft_dprintf(fd_log, ">> call sort_reverse func -- size[%d]\n",
					range->high - range->low);
		sort_reverse(stack_a, stack_b, range->high - range->low);
		if (flag_debug == 1)// for debug
			debug_data(fd_log, stack_a, stack_b);
		return (range->low);
	}

	// ここからが通常の処理
	// pivot_dataを逃す ra
	instruct_rx(stack_a);
	int offset = range->low + 1;//pivot_dataをraさせたため、offsetを足す

// 仕分ける作業：大きい値は　stack_a内に留めて、　小さい値は stack_b に避難する
	count_over = 0;
	count_less = 0;
	i = 0;
	while (i < size)
	{
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, "[%d] is_less_than_range_stack(..., low[%d], high[%d], pivot_data[%d])\n",
				is_less_than_range_stack(stack_a, offset + count_over,
					range->high - count_less + count_over, pivot_data),
				stack_a->data[offset + count_less],
				stack_a->data[range->high - count_less + count_over], pivot_data);

		// 補助：途中で、pivot_data以下の値がない時（つまりstack_bに避難しなくていい場合）
		// 　　　breakして、無駄なraをなくす。
		if (is_less_than_range_stack(stack_a,
				offset + count_over, range->high - count_less + count_over, pivot_data)
					== false)
		{
			if (flag_debug == 1)
				ft_dprintf(fd_log, "break\n");
			break ;
		}

		// 小さい値：stack_b へ避難させる pb
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log,
				">> if ( %d < %d\n", stack_a->data[stack_a->top], pivot_data);
		if (stack_a->data[stack_a->top] < pivot_data)
		{
			instruct_px(stack_b, stack_a);
			count_less++;
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, "count_less++ -> [%d]\n", count_less);
		}

		// 大きい値：stack_a 内でrotateする。
		else
		{
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, ">> call ra\n");
			instruct_rx(stack_a);
			count_over++;
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, "count_over++ -> [%d]\n", count_over);
		}
		i++;
	}


	// 大きい値を元に戻す作業
	if (count_over != stack_a->top)
	{
		if (flag_debug == 1)// for debug
			debug_data(fd_log, stack_a, stack_b);
		i = 0;
		while (i < count_over + 1)
		{
			instruct_rrx(stack_a);
			i++;
		}
	}

	// BOTTOM 側がソートされていたら、BITを立てる
	if (is_sorted_range(stack_a, range->low, stack_a->top) == true)
	{
		range->flag |= BIT_SORTED_BOTTOM_SIDE;
		if (flag_debug == 1)
		{
			ft_dprintf(fd_log,
				">> bottom side is_sorted_range? [%d] true[%d] false[%d]\n",
				is_sorted_range(stack_a, range->low, stack_a->top), true, false);
			debug_data(fd_log, stack_a, stack_b);
		}
	}

// -------------- bottom side と pivot_data 整理完了 --------------
// この時点がpivot_data がstack_a->topになる。（リターン値）
	range->pi = stack_a->top;
	if (flag_debug == 1)//debug
		debug_data(fd_log, stack_a, stack_b);
// ----------------------------------------------------------------

	// TOP側が reverse_sort なら、 reverse_sort する （保留）
	if (is_sorted_range(stack_b, 0, stack_b->top) == true)
	{
		// TOP側のデータを逆ソートにする　stack_a 側に入る。
		i = 0;
		while (i < count_less)
		{
			if (i < count_less - 1)
				instruct_rrx(stack_b);
			instruct_px(stack_a, stack_b);
			i++;
		}
		range->flag |= BIT_SORTED_TOP_SIDE;// TOP側がソート済みになる

		// BOTTOM側もソート済みなら、。。。
		// 未実装
//		if ()
//		{
//		}

		// TOP側のみソート済みなら。。。
		// TOP要素をpbさせて、return(stack_a->top);
//		else
//		{
		// 未実装
//			i = 0;
//			while (i++ < count_less)
//				instruct_px(stack_a, stack_b);
//			if (flag_debug == 1)
//			{
//				ft_dprintf(fd_log, "---- normal end partision function ----\n");
//				debug_data(fd_log, stack_a, stack_b);
//			}
//			return (range->pi);
//		}
	}

	// 通常の処理
	else
	{
		// TOP側のデータがソート済みの場合、stack_b のまま保持させる
		// 注意　呼び出し側（sort_quick側）で検出と特殊処理をする必要あり。
		if (is_reverse_sorted_range(stack_b, 0, stack_b->top) == true)
		{
			if (flag_debug == 1)// debug
			{
				ft_dprintf(fd_log, "---- sorted top side from partition func ----\n");
				debug_data(fd_log, stack_a, stack_b);
			}
			range->flag |= BIT_SORTED_TOP_SIDE;

			// 9/11 KOの原因か？　一旦コメントアウトで無効化
			// さらに、BOTTOM側とTOP側がソート済みなら、stack_b に避難させる
//			if ((range->flag & BIT_SORTED_BOTTOM_SIDE) != 0x00)
//			{
//				i = 0;
//				while (i < count_over + 1)
//				{
//					instruct_px(stack_b, stack_a);
//					i++;
//				}
//			}
			return (stack_a->top);// ソートされていないものだけ返す
		}

		// TOP側がソートされていない場合、paする（stack_a に戻す作業）
		// 通常の処理
		else
		{
			// TOP側を戻す作業
			i = 0;
			while (i++ < count_less)
				instruct_px(stack_a, stack_b);
			if (flag_debug == 1)
			{
				ft_dprintf(fd_log, "---- normal end partision function ----\n");
				debug_data(fd_log, stack_a, stack_b);
			}
			return (range->pi);
		}
	}



	// 避難さていたstack_bの値を戻す作業　(pivot_data > data)
//	else
//	{
//
//		// TOP side　がソートされていたら、BITを立てる　（if文は不要かも。。保留）
//		if (is_sorted_range(stack_a, range->pi + 1, range->high) == true)
//		{
//			range->flag = BIT_SORTED_TOP_SIDE;
//			if (flag_debug == 1)
//			{
//				ft_dprintf(fd_log,
//					">> bottom side is_sorted_range? [%d] true[%d] false[%d]\n",
//					is_sorted_range(stack_a, range->low, stack_a->top), true, false);
//				debug_data(fd_log, stack_a, stack_b);
//			}
//		}
//
//		if ((range->flag & BIT_SORTED_TOP_SIDE) > 1)
//		{
//			// 避難していたTOP側が　is_sort_range　なら、STACK_Aに戻さなくていい
//			// つまり余計なpa,pbをなくせる
//			//   pa  partition内で避難していたデータを戻さなくていい
//			// 　pb  呼び出し側のsort_quickでの余分なpbをなくせる (方法は要検討)
//			while (i++ < size)
//				instruct_px(stack_b, stack_a);
//			(range->flag_sorted) = true;
//			return (stack_a->top);
//		}
//	}

//	if (flag_debug == 1)
//		debug_data(fd_log, stack_a, stack_b);
	return (range->pi);
}
