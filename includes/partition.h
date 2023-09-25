/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:01:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 17:41:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file partition.h
 * @brief Define partition functions
 */
#ifndef PARTITION_H
# define PARTITION_H

# include "push_swap.h"

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

//void	sort_quick(t_stack *src, t_stack *tmp, t_range range);
void	sort_quick(t_stack *src, t_stack *tmp, t_range range, t_count count);
//void	recursive_top_side(t_stack *src, t_stack *tmp, t_range range);
void	recursive_top_side(t_stack *src, t_stack *tmp, t_range range, t_count count);
void	recursive_bottom_side(t_stack *src, t_stack *tmp,
		t_range range, t_count count);

// partition functions
void	partition(t_stack *src, t_stack *tmp, t_range range, t_count *count);
void	move_data_bottom_side(t_stack *src, t_stack *tmp,
		t_count *count, int pivot_data, int min_data);
void	partition_reverse(t_stack *src, t_stack *tmp, t_range range, t_count *count);
void	move_data_top_side(t_stack *src, t_stack *tmp,
		t_count *count, int pivot_data, int min_data);
void	end_process(t_stack *src, t_stack *tmp, t_range range);

// partition_small
void	partition_three_elements(t_stack *src, t_stack *tmp, t_range range);

void	sort_reverse(t_stack *stack_a, t_stack *stack_b, int size);
void	set_transition(t_transition *transition,
			t_count count, t_range range, t_stack *src, t_stack *tmp);

/**
 * @brief This sort function using the insertion sort algorithm
 */
void	sort_insert(t_stack *stack_a, t_stack *stack_b);

// call by function ( partition or partition_reverse )
int	get_pivot_data(t_stack *stack, t_range range);
int	get_min_data(t_stack *stack, int low, int high);
int	*allocate_array(int	size);
void	move_min_data(t_stack *stack_a, t_stack *stack_b, t_count count);

void	init_count(t_count *count);

#endif
