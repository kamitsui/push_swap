/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruction.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:42:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 13:26:40 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_INSTRUCTION_H
# define CHECKER_INSTRUCTION_H

/**
 * @brief Function pointer for collecting is_instruction_**\n
 * (search_type_instruction use this)
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
