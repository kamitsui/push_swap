/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_ss.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:48:58 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 11:05:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_ss.c
 * @brief check if ss
 */
#include "checker.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if ss
 *
 * @param instruction is the string to search
 *
 * @return INST_SS("ss") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_ss(char *instruction)
{
	if (ft_strnequ(instruction, "ss", 2) == true)
		return (INST_SS);
	else
		return (INST_DEFAULT);
}
