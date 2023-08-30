/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:46:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 13:25:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"
#include "ft_printf.h"
#include "get_next_line.h"

/**
 * @brief checker function for push_swap
 *
 * @param stack_a 
 * @param stack_b
 * @param size
 *
 * @return 
 */
int	checker(t_stack *stack_a, t_stack stack_b, size_t size)
{
	char				*instruction;
	enum e_instruction	type;

	while (true)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (instruction == NULL)
			break ;
		type = search_type_instruction(instruction);
		if (type != INST_ERROR)
			execute_instruction(type);
		else
			break ;
		ft_printf("%s %d", instruction, (int)type);
		free(instruction);
	}
	// Check if the stacks are sorted and empty
	if (is_sorted(stack_a) && is_empty(stack_b))
	{
		ft_printf("OK\n");
		return (0);
	}
	ft_printf("KO\n");
	return (1);
}
