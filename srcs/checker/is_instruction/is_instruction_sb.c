/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_sb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:50:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 12:33:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_sb.c
 * @brief check if sb
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if sb
 *
 * @param instruction is the string to search
 *
 * @return INST_SB("sb") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_sb(char *instruction)
{
	if (ft_strnequ(instruction, "sb", 2) == true)
		return (INST_SB);
	else
		return (INST_DEFAULT);
}
