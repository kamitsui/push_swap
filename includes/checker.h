/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:42:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 10:46:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEKER_H
# define CHEKER_H

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

/**
 */
enum e_instruction	search_type_instruction(char *instruction);

/**
 */
typedef enum e_instruction	(*t_f_is_instruction)(char *instruction);

/**
 * @brief check if rrr
 */
enum e_instruction	is_instruction_rrr(char *instruction);

/**
 * @brief check if rra
 */
enum e_instruction	is_instruction_rra(char *instruction);

/**
 * @brief check if rrb
 */
enum e_instruction	is_instruction_rrb(char *instruction);

/**
 * @brief check if rr
 */
enum e_instruction	is_instruction_rr(char *instruction);

/**
 * @brief check if ra
 */
enum e_instruction	is_instruction_ra(char *instruction);

/**
 * @brief check if rb
 */
enum e_instruction	is_instruction_rb(char *instruction);

/**
 * @brief check if pa
 */
enum e_instruction	is_instruction_pa(char *instruction);

/**
 * @brief check if pb
 */
enum e_instruction	is_instruction_pb(char *instruction);

/**
 * @brief check if sa
 */
enum e_instruction	is_instruction_sa(char *instruction);

/**
 * @brief check if sb
 */
enum e_instruction	is_instruction_sb(char *instruction);

/**
 * @brief check if ss
 */
enum e_instruction	is_instruction_ss(char *instruction);

/**
 * @brief non existent instruction
 */
enum e_instruction	is_instruction_error(char *instruction);

#endif
