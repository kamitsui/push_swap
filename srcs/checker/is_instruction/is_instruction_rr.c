/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:57:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:58:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_rr.c
 * @brief check if rr
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if rr
 *
 * @param instruction is the string to search
 *
 * @return INST_RR("rr") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_rr(char *instruction)
{
	size_t	n;

	n = ft_strlen(instruction) - 1;
	if (ft_strnequ(instruction, "rr", n) == true)
		return (INST_RR);
	else
		return (INST_DEFAULT);
}
