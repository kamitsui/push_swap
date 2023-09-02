/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_sb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:50:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:59:53 by kamitsui         ###   ########.fr       */
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
	size_t	n;

	n = ft_strlen(instruction) - 1;
	if (ft_strnequ(instruction, "sb", n) == true)
		return (INST_SB);
	else
		return (INST_DEFAULT);
}
