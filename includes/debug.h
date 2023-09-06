/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:36:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/06 17:19:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "push_swap.h"
# define ONE_LINE	"----------\n"

void	debug_data(t_stack *left, t_stack *right);
void	repeat_push(t_stack *dst, t_stack *src, int num);
void	repeat_swap(t_stack *target, int num);
void	repeat_swap_same(t_stack *target1, t_stack *target2, int num);
void	repeat_rotate(t_stack *target, int num);
void	repeat_rotate_same(t_stack *target1, t_stack *target2, int num);
void	repeat_reverse_rotate(t_stack *target, int num);
void	repeat_reverse_rotate_same(t_stack *target1, t_stack *target2, int num);
int		open_log(const char *file_name, int oflag);

int	fd_log;

#endif
