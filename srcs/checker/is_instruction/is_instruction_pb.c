/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction_pb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:53:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 11:07:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_instruction_pb.c
 * @brief check if pb
 */
#include "checker.h"
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
	if (ft_strnequ(instruction, "pb", 2) == true)
		return (INST_PB);
	else
		return (INST_DEFAULT);
}
