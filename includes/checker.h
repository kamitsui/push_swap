/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 13:25:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_INSTRUCTION_H
# define CHECKER_INSTRUCTION_H

/**
 * @brief e_instruction is e_num type of instruction to stack
 * @details
 * INST_PA : push stack_a from stack_b\n
 * INST_PB : push stack_b from stack_a\n
 * INST_SA : swap 1st and 2nd element in stack a\n
 * INST_SB : swap 1st and 2nd element in stack b\n
 * INST_SS : swap a and swap b at the same time\n
 * INST_RA : rotate 1st becomes the last in stack_a\n
 * INST_RB : rotate 1st becomes the last in stack_b\n
 * INST_RR : rotate a and rotate b at the same time\n
 * INST_RRA : reverse rotate last becomes the 1st in stack_a\n
 * INST_RRB : reverse rotate last becomes the 1st in stack_b\n
 * INST_RRR : reverse rotate a and rotate b at the same time\n
 */
enum	e_instruction
{
	INST_DEFAULT,
	INST_RRR,
	INST_RRA,
	INST_RRB,
	INST_RR,
	INST_RA,
	INST_RB,
	INST_PA,
	INST_PB,
	INST_SA,
	INST_SB,
	INST_SS,
	INST_ERROR
};

int	checker(t_stack *stack_a, t_stack stack_b, size_t size);

/**
 * @brief search type from instruction string
 */
enum e_instruction	search_type_instruction(char *instruction);

# include "push_swap.h"

void	execute_instruction(enum e_instruction type,
							t_stack *stack_a, t_stack *stack_b);

#endif
