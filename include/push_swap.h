/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:04:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/01 17:22:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

#define MAX_SIZE 100

// Stack data structure
//  top : Index of the top element in the stack
typedef struct s_Stack
{
    int data[MAX_SIZE];
    int top; // Index of the top element in the stack
}	t_Stack;

int	*allocate_array(size_t size);
void	set_data(t_Stack *Stack, int argc, char *argv[]);
void	debug_data(t_Stack *a, t_Stack *b);

#endif
