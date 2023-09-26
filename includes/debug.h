/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:36:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:47:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "push_swap.h"
# include "quick_sort.h"

# define ONE_LINE	"----------\n"
# define DEBUG_OFF	0
# define DEBUG_ON	1

int	g_fd_log;
int	g_flag_debug;

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
// -------------------------------------------------

// ---------- call by this functions ----------
// exist in debug_range.c
//   recursive_top_side , recursive_bottom_side, sort_quick
void	debug_range(t_range range);
void	debug_before_range(t_range range);
void	debug_after_range(t_range range);
void	debug_recursive(t_range range);
// -------------------------------------------------

// ---------- call by move_data functions ----------
// exist in debug_move_data.c
void	debug_move_data(int min_data, int move_data, int mode);
void	debug_count_min(int count);
void	debug_count_less(int count);
void	debug_count_over(int count);
// -------------------------------------------------

// ---------- call by move_large_data functions ----------
// exist in debug_move_large_data.c
void	debug_number_of_ra(t_stack *src, t_count count);
void	debug_number_of_rra(t_count count);
void	debug_move_large_data(t_stack *src);
// -------------------------------------------------

// ---------- call by partition functions ----------
// exist in debug_partition.c
void	debug_partition_start(int mode);
void	debug_after_transition(t_range range);
void	debug_current_data(t_stack *src, t_range range);
// -------------------------------------------------

// ---------- call by end_process functions ----------
// exist in debug_end_process.c
void	debug_end_process_start(int mode);
// -------------------------------------------------

// ---------- call by this functions ----------
// get_pivot_data , get_min_data
// exist in debug_array.c
void	debug_array(int arr[], int size);
void	debug_array_before(int arr[], int size);
void	debug_array_after(int arr[], int size);
// -------------------------------------------------

// ---------- call by get_pivot_data function ----------
// exist in debug_pivot_data.c
void	debug_get_pivot_data_start(t_range range, int size);
void	debug_median_even(long mid1, long mid2, int median);
void	debug_median_odd(int median);
// -------------------------------------------------

// ---------- call by this functions ----------
// instruct_sx , instruct_ss , instruct_px
// exist in debug_instruct_push_and_swap.c
void	debug_instruct_px(const char *name);
void	debug_instruct_sx(const char *name);
void	debug_instruct_ss(void);
// -------------------------------------------------
// instruct_rx , instruct_rr , instruct_rrx
// exist in debug_instruct_rotate.c
void	debug_instruct_rx(const char *name);
void	debug_instruct_rr(void);
void	debug_instruct_rrx(const char *name);
void	debug_instruct_rrr(void);
// -------------------------------------------------

#endif
