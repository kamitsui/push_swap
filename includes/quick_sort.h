/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:01:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 13:52:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file quick_sort.h
 * @brief Define quick_sort functions
 */
#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include "push_swap.h"

typedef struct s_range
{
	int	low;
	int	high;
	int	pivot_data;
	int	min_data;
	int	mode;
	int	transition_low;
	int	transition_high;
}	t_range;

typedef struct s_count
{
	int	over;
	int	less;
	int	min;
}	t_count;

# define BOTTOM_SIDE	0
# define TOP_SIDE		1

// sort_quick functions
void	sort_quick(t_stack *src, t_stack *tmp, t_range range, t_count count);
void	recursive_top_side(
			t_stack *src, t_stack *tmp, t_range range, t_count count);
void	recursive_bottom_side(
			t_stack *src, t_stack *tmp, t_range range, t_count count);

// partition functions
void	partition(t_stack *src, t_stack *tmp, t_range range, t_count *count);
void	partition_bottom_side(
			t_stack *src, t_stack *tmp, t_range range, t_count *count);
void	partition_top_side(
			t_stack *src, t_stack *tmp, t_range range, t_count *count);

// partition utils
// ---------- call by this functions ----------
//   partition_bottom_side , partition_top_side
void	move_data(t_stack *src, t_stack *tmp, t_count *count, t_range range);
void	move_large_data(t_stack *src, t_count count);
void	end_process(t_stack *src, t_stack *tmp, t_range range);
void	set_transition(
			t_stack *src, t_stack *tmp, t_count count, t_range *range);
int		get_pivot_data(t_stack *stack, t_range range);
int		get_min_data(
			t_stack *stack, t_stack *tmp, t_range range, t_count count);
void	move_min_data(t_stack *stack_a, t_stack *stack_b, t_count count);

// ---------- call by this functions ----------
//   get_pivot_data , get_min_data
int		*allocate_array(int size);
// -------------------------------------------------

#endif
