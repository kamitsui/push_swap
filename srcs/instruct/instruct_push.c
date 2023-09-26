/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:49:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_push.c
 * @brief execute ( pa | pb ) & output ( "pa\n" | "pb\n" )
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

// for debug
#include "debug.h"

/**
 * @brief execute ( pa | pb ) & output ( "pa\n" | "pb\n" )
 *
 * @param dst : push one element to "dst" stack
 * @param src : pop first element from "src" stack
 */
void	instruct_px(t_stack *dst, t_stack *src)
{
	execute_px(dst, src);
	ft_printf("p%s\n", dst->name);
}
//debug code
//	debug_instruct_px(dst->name);
