/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:01:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/08 14:45:17 by kamitsui         ###   ########.fr       */
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
	bool	*flag_sorted;
}	t_range;

//void	sort_quick(t_stack *stack_a, t_stack *stack_b, int low, int high);
void	sort_quick(t_stack *stack_a, t_stack *stack_b, t_range range);
//int	partition(t_stack *stack_a, t_stack *stack_b, int low, int high);
//int	partition(t_stack *stack_a, t_stack *stack_b, t_range range, bool *flag_sorted);
int	partition(t_stack *stack_a, t_stack *stack_b, t_range range);

void	sort_reverse(t_stack *stack_a, t_stack *stack_b, int size);

/**
 * @brief This sort function using the insertion sort algorithm
 */
void	sort_insert(t_stack *stack_a, t_stack *stack_b);

#endif
