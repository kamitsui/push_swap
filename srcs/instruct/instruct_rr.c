/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:43:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 17:10:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct_rr.c
 * @brief execute rr & output "rr\\n"
 */
#include "push_swap.h"
#include "instruct.h"
#include "ft_printf.h"

/**
 * @brief execute instruction rr
 *
 * @param target1 to rotate
 * @param target2 to rotate
 */
static void	execute_rr(t_stack *target1, t_stack *target2)
{
	execute_rx(target1);
	execute_rx(target2);
}

/**
 * @brief execute rr & output "rr\\n"
 *
 * @param target1 to rotate
 * @param target2 to rotate
 */
void	instruct_rr(t_stack *target1, t_stack *target2)
{
	execute_rr(target1, target2);
	ft_printf("rr\n");
}
