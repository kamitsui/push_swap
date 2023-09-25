/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:36:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 17:02:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "push_swap.h"
# include "sort.h"

# define ONE_LINE	"----------\n"
# define DEBUG_OFF	0
# define DEBUG_ON	1

int	g_fd_log;// debug
int	g_flag_debug;//debug

void	debug_data(int debug_fd, t_stack *left, t_stack *right);
void	repeat_push(t_stack *dst, t_stack *src, int num);
void	repeat_swap(t_stack *target, int num);
void	repeat_swap_same(t_stack *target1, t_stack *target2, int num);
void	repeat_rotate(t_stack *target, int num);
void	repeat_rotate_same(t_stack *target1, t_stack *target2, int num);
void	repeat_reverse_rotate(t_stack *target, int num);
void	repeat_reverse_rotate_same(t_stack *target1, t_stack *target2, int num);
int		open_log(const char *file_name, int oflag);

// ---------- call by sort_quick function ----------
// exist in debug_sort_quick.c
void	debug_sort_quick_start(t_stack *src, t_stack *tmp, t_range range);
void	debug_sort_quick_end(t_stack *src, t_stack *tmp, t_range range);
void	debug_after_partition(t_stack *src, t_stack *tmp, t_range range);
void	debug_after_recursive_top_side(
		t_stack *src, t_stack *tmp, t_range range);
void	debug_after_recursive_bottom_side(
		t_stack *src, t_stack *tmp, t_range range);
// ---------- call by this functions ----------
//   recursive_top_side , recursive_bottom_side, sort_quick
void	debug_range(t_range range);
void	debug_before_range(t_range range);
void	debug_after_range(t_range range);

// get_pivot_data , get_min_data
void	debug_array(int arr[], int size);

#endif
