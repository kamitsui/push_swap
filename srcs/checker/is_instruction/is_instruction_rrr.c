/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_rrr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:00:37 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:59:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_rrr.c
 * @brief check if rrr
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if rrr
 *
 * @param instruction is the string to search
 *
 * @return INST_RRR("rrr") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_rrr(char *instruction)
{
	size_t	n;

	n = ft_strlen(instruction) - 1;
	if (ft_strnequ(instruction, "rrr", n) == true)
		return (INST_RRR);
	else
		return (INST_DEFAULT);
}
