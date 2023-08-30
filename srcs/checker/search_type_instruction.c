/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_type_instruction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:33:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 12:01:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief search type from instruction string
 *
 * @param instruction is the string to search
 *
 * @return type is the instruction type ( enum e_instruction )
 */
enum e_instruction	search_type_instruction(char *instruction)
{
	enum e_instruction			type;
	size_t						i;
	const t_f_is_instruction	is_instructions[INST_ERROR] = {
		is_instruction_rrr, is_instruction_rra, is_instruction_rrb,
		is_instruction_rr, is_instruction_ra, is_instruction_rb,
		is_instruction_pa, is_instruction_pb,
		is_instruction_ss, is_instruction_sa, is_instruction_sb,
		is_instruction_error};

	i = 0;
	type = INST_DEFAULT;
	while (type == INST_DEFAULT)
	{
		type = is_instructions[i](instruction);
		i++;
	}
	return (type);
}
