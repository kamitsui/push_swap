/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:43:54 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 20:48:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	read_instruction(char *instruction)
{
	while (true)
	{
		instruction = get_next_line(STDIN_FILE_NO);
		if (instruction == NULL)
			break ;
		free(instruction);
	}
}
