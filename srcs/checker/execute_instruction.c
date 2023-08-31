/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:15:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/31 12:42:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruct.h"
#include "checker.h"
#include "checker_instruction.h"

//void	test_a(t_stack *stack_a, t_stack *stack_b)
//{
//	(void)stack_a;
//	(void)stack_b;
//}
//
//void	test_b(t_stack *dst, t_stack *src)
//{
//	(void)dst;
//	(void)src;
//}

//typedef void	(*t_f_execute)(t_stack *target1, t_stack *target2);

void	execute_instruction(enum e_instruction type,
							t_stack *stack_a, t_stack *stack_b)
{
//	static t_f_execute	execute[12] = {
//			execute_rrr, execute_rra, execute_rrb,
//			execute_rr, execute_ra, execute_rb,
//			execute_pa, execute_pb,
//			execute_sa, execute_sb, execute_ss};
//
//	execute[type](stack_a, stack_b);
}
