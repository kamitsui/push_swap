/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_pa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:54:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:53:11 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_pa.c
 * @brief check if pa
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>
#include "ft_printf.h"//debgu
/**
 * @brief check if pa
 *
 * @param instruction is the string to search
 *
 * @return INST_PA("pa") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_pa(char *instruction)
{
	size_t	n;

	n = ft_strlen(instruction) - 1;
	if (ft_strnequ(instruction, "pa", n) == true)
		return (INST_PA);
	else
		return (INST_DEFAULT);
}
