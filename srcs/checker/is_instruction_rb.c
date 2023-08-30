/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_rb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:55:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 11:06:53 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_rb.c
 * @brief check if rb
 */
#include "checker.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if rb
 *
 * @param instruction is the string to search
 *
 * @return INST_RB("rb") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_rb(char *instruction)
{
	if (ft_strnequ(instruction, "rb", 2) == true)
		return (INST_RB);
	else
		return (INST_DEFAULT);
}
