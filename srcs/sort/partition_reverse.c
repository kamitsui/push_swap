/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:57:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/13 16:26:02 by kamitsui         ###   ########.fr       */
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

static void	debug_partition(t_stack *stack, t_range range, int pivot_data)
{
	int	size;

	size = range.high - range.low;
	ft_dprintf(fd_log, "pivot_data[%d] size[%d]=high[%d]-low[%d] top[%d]\n",
		pivot_data, size, range.high, range.low, stack->top);
}

static void	debug_is_less_than_stack_range(t_stack *stack, int low, int high, int pivot_data)
{
	ft_dprintf(fd_log, "pivot_data[%d] > data[%d] ~ data[%d]\n",
		pivot_data, low, high);
	ft_dprintf(fd_log, ">> is_less_than_stack_range = [%d] false[%d] true[%d]\n",
		is_less_than_stack_range(stack, low, high, pivot_data), false, true);
}

void	partition_reverse(t_stack *src, t_stack *tmp, t_range *range)
{
	int	pivot_data;
	int	size;
	int	i;
	int	count_over;
	int	count_less;
	flag_debug = 1;
	//int	mode = (range->flag & BIT_MODE_REVERSE) > 0;

	if (flag_debug == 1)//debug
	{
		ft_dprintf(fd_log, ">> call partition reverse\n");
		debug_data(fd_log, src, tmp);
	}

	pivot_data = src->data[range->high];
	size = range->high - range->low;

	if (flag_debug == 1)// debug
		debug_partition(src, *range, pivot_data);
//		ft_dprintf(fd_log, "pivot_data[%d] size[%d]=high[%d]-low[%d] top[%d]\n",
//			pivot_data, size, range->high, range->low, src->top);

	// ----------------   ?? 不要になるかも　保留 -----------------
	// pivot_dataまで（range外のデータ）をtmpに避難させる
//	while (range->high < src->top)
//		instruct_px(tmp, src);

//	if (flag_debug == 1)// debug
//		ft_dprintf(fd_log, "[%d]pivot_data\n", pivot_data);

	// is_less_than_in_stack_range
	// ピボットの値未満しかなければ、以下の処理をせず、range->highを返す
	// 期待効果は、無駄な命令が減る。
	if (flag_debug == 1)// debug
	{
		debug_is_less_than_stack_range(src, range->low, range->high, pivot_data);
//		ft_dprintf(fd_log, "pivot_data[%d] > range.low ~ range.high\n", pivot_data);
//		ft_dprintf(fd_log, ">> is_less_than_stack_range = [%d] true[%d] false[%d]\n",
//			is_less_than_stack_range(src, range->low, range->high, pivot_data));
	}

	// 目的：pivot_dataが一番大きい値なら、BOTTOM側は作らなくていい。highをそのままpiとして返す
	if (is_less_than_stack_range(src, range->low, range->high, pivot_data) == false)
		//return (range->high);

	// range内のデータが逆順だったら、逆sortをさせる。
	// この条件だめかも？？　bottom側のデータも見てしまっているため? 保留
	if (is_reverse_sorted_range(src, range->low, range->high) == true)
	{
		if (flag_debug == 1)// for debug
			ft_dprintf(fd_log, ">> call sort_reverse func -- size[%d]\n",
					range->high - range->low);
		sort_reverse(src, tmp, range->high - range->low);
		if (flag_debug == 1)// for debug
			debug_data(fd_log, src, tmp);
	//	return (range->high);
	}

	// ここからが通常の処理
	// pivot_dataを逃す push src->tmp + rotate src
	instruct_px(tmp, src);
	instruct_rx(tmp);
	count_over = 1;//pivot_dataをpushさせたため、count_overを足す
	int offset = 0;// non meening

// 仕分ける作業：大きい値は　src内に留めて、　小さい値は tmp に避難する
	//count_over = 0;
	count_less = 0;
	i = 0;
	while (i < size)
	{
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log, "[%d] is_less_than_range_stack(..., low[%d], high[%d], pivot_data[%d])\n",
				is_less_than_stack_range(src, offset + count_over,
					range->high - count_less + count_over, pivot_data),
				src->data[offset + count_less],
				src->data[range->high - count_less + count_over], pivot_data);

		// 補助：途中で、pivot_data以下の値がない時（つまりtmpに避難しなくていい場合）
		// 　　　breakして、無駄なraをなくす。
		if (is_less_than_stack_range(src,
				offset + count_over, range->high - count_less + count_over, pivot_data)
					== false)
		{
			if (flag_debug == 1)
				ft_dprintf(fd_log, "break\n");
			break ;
		}

		// 小さい値：src 内でrotateする。
		if (flag_debug == 1)// debug
			ft_dprintf(fd_log,
				">> if ( %d < %d\n", src->data[src->top], pivot_data);
		if (src->data[src->top] < pivot_data)
		{
			instruct_rx(src);
			count_less++;
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, "count_less++ -> [%d]\n", count_less);
		}

		// 小さい値：tmp へ避難させる push tmp
		else
		{
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, ">> call ra\n");
			instruct_px(tmp, src);
			count_over++;
			if (flag_debug == 1)// debug
				ft_dprintf(fd_log, "count_over++ -> [%d]\n", count_over);
		}
		i++;
	}

	// pivot_dataをtmpのtopに戻す
	instruct_rrx(tmp);


//	// BOTTOM 側がソートされていたら、BITを立てる
//	if (is_sorted_range(src, range->low, src->top) == true)
//	{
//		range->flag |= BIT_SORTED_BOTTOM_SIDE;
//		if (flag_debug == 1)
//		{
//			ft_dprintf(fd_log,
//				">> bottom side is_sorted_range? [%d] true[%d] false[%d]\n",
//				is_sorted_range(src, range->low, src->top), true, false);
//			debug_data(fd_log, src, tmp);
//		}
//	}

// -------------- bottom side と pivot_data 整理完了 --------------
// この時点がpivot_data がsrc->topになる。（リターン値）
	range->pi = src->top;
	range->high = src->top;
	range->low = 0;
	if (flag_debug == 1)//debug
		debug_data(fd_log, src, tmp);
// ----------------------------------------------------------------

//	// TOP側が reverse_sort なら、 reverse_sort する （保留）
//	if (is_sorted_range(tmp, 0, tmp->top) == true)
//	{
//		// TOP側のデータを逆ソートにする　src 側に入る。
//		i = 0;
//		while (i < count_less)
//		{
//			if (i < count_less - 1)
//				instruct_rrx(tmp);
//			instruct_px(src, tmp);
//			i++;
//		}
//		range->flag |= BIT_SORTED_TOP_SIDE;// TOP側がソート済みになる
//
//		// BOTTOM側もソート済みなら、。。。
//		// 未実装
//		if ()
//		{
//		}

		// TOP側のみソート済みなら。。。
		// TOP要素をpbさせて、return(src->top);
//		else
//		{
		// 未実装
//			i = 0;
//			while (i++ < count_less)
//				instruct_px(src, tmp);
//			if (flag_debug == 1)
//			{
//				ft_dprintf(fd_log, "---- normal end partision function ----\n");
//				debug_data(fd_log, src, tmp);
//			}
//			return (range->pi);
//		}
//	}

//	// 通常の処理
//	else
//	{
//		// TOP側のデータがソート済みの場合、tmp のまま保持させる
//		// 注意　呼び出し側（sort_quick側）で検出と特殊処理をする必要あり。
//		if (is_reverse_sorted_range(tmp, 0, tmp->top) == true)
//		{
//			if (flag_debug == 1)// debug
//			{
//				ft_dprintf(fd_log, "---- sorted top side from partition func ----\n");
//				debug_data(fd_log, src, tmp);
//			}
//			range->flag |= BIT_SORTED_TOP_SIDE;

			// 9/11 KOの原因か？　一旦コメントアウトで無効化
			// さらに、BOTTOM側とTOP側がソート済みなら、tmp に避難させる
//			if ((range->flag & BIT_SORTED_BOTTOM_SIDE) != 0x00)
//			{
//				i = 0;
//				while (i < count_over + 1)
//				{
//					instruct_px(tmp, src);
//					i++;
//				}
//			}
//			return (src->top);// ソートされていないものだけ返す
//		}

		// TOP側がソートされていない場合、paする（src に戻す作業）
		// 通常の処理
//		else
//		{
//			// TOP側を戻す作業
//			i = 0;
//			while (i++ < count_less)
//				instruct_px(src, tmp);
//			if (flag_debug == 1)
//			{
//				ft_dprintf(fd_log, "---- normal end partision function ----\n");
//				debug_data(fd_log, src, tmp);
//			}
//			return (range->pi);
//		}
//	}



	// 避難さていたtmpの値を戻す作業　(pivot_data > data)
//	else
//	{
//
//		// TOP side　がソートされていたら、BITを立てる　（if文は不要かも。。保留）
//		if (is_sorted_range(src, range->pi + 1, range->high) == true)
//		{
//			range->flag = BIT_SORTED_TOP_SIDE;
//			if (flag_debug == 1)
//			{
//				ft_dprintf(fd_log,
//					">> bottom side is_sorted_range? [%d] true[%d] false[%d]\n",
//					is_sorted_range(src, range->low, src->top), true, false);
//				debug_data(fd_log, src, tmp);
//			}
//		}
//
//		if ((range->flag & BIT_SORTED_TOP_SIDE) > 1)
//		{
//			// 避難していたTOP側が　is_sort_range　なら、srcに戻さなくていい
//			// つまり余計なpa,pbをなくせる
//			//   pa  partition内で避難していたデータを戻さなくていい
//			// 　pb  呼び出し側のsort_quickでの余分なpbをなくせる (方法は要検討)
//			while (i++ < size)
//				instruct_px(tmp, src);
//			(range->flag_sorted) = true;
//			return (src->top);
//		}
//	}

//	if (flag_debug == 1)
//		debug_data(fd_log, src, tmp);
	if (flag_debug == 1)
	{
		ft_dprintf(fd_log, "-- range low[%d] high[%d] pi[%d]\n",
				range->low, range->high, range->pi);
		ft_dprintf(fd_log, "---- end partision_reverse ----\n");
	}
	//return (range->pi);
}
