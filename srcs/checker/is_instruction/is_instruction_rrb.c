/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_rrb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:58:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:59:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_rrb.c
 * @brief check if rrb
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if rrb
 *
 * @param instruction is the string to search
 *
 * @return INST_RRB("rrb") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_rrb(char *instruction)
{
	size_t	n;

	n = ft_strlen(instruction) - 1;
	if (ft_strnequ(instruction, "rrb", n) == true)
		return (INST_RRB);
	else
		return (INST_DEFAULT);
}
