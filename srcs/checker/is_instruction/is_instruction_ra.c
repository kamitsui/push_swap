/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_ra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:56:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 12:32:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_ra.c
 * @brief check if ra
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if ra
 *
 * @param instruction is the string to search
 *
 * @return INST_RA("ra") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_ra(char *instruction)
{
	if (ft_strnequ(instruction, "ra", 2) == true)
		return (INST_RA);
	else
		return (INST_DEFAULT);
}
