/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:08:40 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 13:27:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCT_H
# define INSTRUCT_H

/**
 * @brief 命令の関数 ( instructions.c )
 */
void	push_data(t_stack *dst, t_stack *src);
void	swap_one(t_stack *target);
void	swap_two(t_stack *target1, t_stack *target2);
void	rotate_one(t_stack *target);
void	rotate_two(t_stack *target1, t_stack *target2);
void	reverse_rotate_one(t_stack *target);
void	reverse_rotate_two(t_stack *target1, t_stack *target2);

#endif
