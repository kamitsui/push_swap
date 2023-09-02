/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_pb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:53:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 14:53:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_pb.c
 * @brief check if pb
 */
#include "checker_instruction.h"
#include "libft.h"
#include <stdbool.h>

/**
 * @brief check if pb
 *
 * @param instruction is the string to search
 *
 * @return INST_PB("pb") or INST_DEFAULT(other)
 */
enum e_instruction	is_instruction_pb(char *instruction)
{
	size_t	n;

	n = ft_strlen(instruction) - 1;
	if (ft_strnequ(instruction, "pb", n) == true)
		return (INST_PB);
	else
		return (INST_DEFAULT);
}
