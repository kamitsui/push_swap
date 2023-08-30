/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_rra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:59:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 12:32:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_rra.c
 * @brief check if rra
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if rra
 *
 * @param instruction is the string to search
 *
 * @return INST_RRA("rra") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_rra(char *instruction)
{
	if (ft_strnequ(instruction, "rra", 3) == true)
		return (INST_RRA);
	else
		return (INST_DEFAULT);
}
