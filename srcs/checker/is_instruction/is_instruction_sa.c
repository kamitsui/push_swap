/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_sa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:51:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:59:40 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_sa.c
 * @brief check if sa
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if sa
 *
 * @param instruction is the string to search
 *
 * @return INST_SA("sa") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_sa(char *instruction)
{
	size_t	n;

	n = ft_strlen(instruction) - 1;
	if (ft_strnequ(instruction, "sa", n) == true)
		return (INST_SA);
	else
		return (INST_DEFAULT);
}
