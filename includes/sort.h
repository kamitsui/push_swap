/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:01:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/13 15:51:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sort.h
 * @brief Define sort functions
 */
#ifndef SORT_H
# define SORT_H

void	sort(t_stack *stack_a, t_stack *stack_b, size_t size);
void	sort_small(t_stack *stack_a, t_stack *stack_b, size_t size);

void	sort_two_elements(t_stack *stack_a);
void	sort_three_elements(t_stack *stack_a);
void	sort_six_elements(t_stack *stack_a, t_stack *stack_b);

typedef struct s_range
{
	int	low;
	int	high;
	int	pi;
	int		flag;
}	t_range;

#define BIT_UNSORTED			0x01
//#define BIT_SORTED_TOP_SIDE		0x01// 不要になるかも
//#define BIT_SORTED_BOTTOM_SIDE	0x02// 不要になるかも
#define BIT_MODE_REVERSE		0x02

void	sort_quick(t_stack *src, t_stack *tmp, t_range range);
void	partition(t_stack *stack_a, t_stack *stack_b, t_range *range);
void	partition_reverse(t_stack *stack_a, t_stack *stack_b, t_range *range);

void	sort_reverse(t_stack *stack_a, t_stack *stack_b, int size);

/**
 * @brief This sort function using the insertion sort algorithm
 */
void	sort_insert(t_stack *stack_a, t_stack *stack_b);

typedef bool	(*t_f_is_sorted_direction)(t_stack *, int, int);

#endif
