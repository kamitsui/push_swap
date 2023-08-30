/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:47:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 12:31:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_error.c
 * @brief non existent instruction
 */
#include "checker_instruction.h"

/**
 * @brief non existent instruction
 *
 * @param instruction is the string to search
 *
 * @return INST_ERROR
 */
enum e_instruction	is_instruction_error(char *instruction)
{
	(void)instruction;
	return (INST_ERROR);
}
