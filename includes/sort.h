/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:01:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/22 19:17:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort.h
 * @brief Define sort functions
 */
#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b, size_t size);
void	sort_small(t_stack *src, t_stack *tmp, size_t size, int mode);

void	sort_two_elements(t_stack *stack, int mode);
void	sort_three_elements(t_stack *stack, int mode);
void	sort_six_elements(t_stack *src, t_stack *tmp, int mode);

typedef struct s_range
{
	int	low;
	int	high;
	int	mode;
}	t_range;

typedef struct s_count
{
	int	over;
	int	less;
	int	min;
}	t_count;

typedef struct s_transition
{
	int	low;
	int	high;
}	t_transition;

# define MODE_NORMAL		0
# define MODE_REVERSE	1

void	sort_quick(t_stack *src, t_stack *tmp, t_range range);
void	recursive_top_side(
			t_stack *src, t_stack *tmp, t_range range, int original_tmp_top);
void	recursive_bottom_side(
		t_stack *src, t_stack *tmp, t_range range, int original_tmp_top, t_count count);
void	partition(t_stack *src, t_stack *tmp, t_range range, t_count *count);
void	partition_reverse(t_stack *src, t_stack *tmp, t_range range, t_count *count);
//void	end_process(t_stack *src, t_stack *tmp, int mode);
//void	end_process(t_stack *src, t_stack *tmp,
//		int original_tmp_top, int mode);
void	end_process(t_stack *src, t_stack *tmp, t_range range, t_count count);

// partition_small
void	partition_three_elements(t_stack *src, t_stack *tmp, t_range range);

void	sort_reverse(t_stack *stack_a, t_stack *stack_b, int size);
void	set_transition(t_transition *transition,
			t_count count, t_range range, t_stack *src);

/**
 * @brief This sort function using the insertion sort algorithm
 */
void	sort_insert(t_stack *stack_a, t_stack *stack_b);

// call by function ( partition or partition_reverse )
int	get_pivot_data(t_stack *stack, t_range range);
int	get_min_data(t_stack *stack, int low, int high);
int	*allocate_array(int	size);
void	move_min_data(t_stack *stack_a, t_stack *stack_b, int count);

#endif
