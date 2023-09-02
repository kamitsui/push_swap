/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:46:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 13:05:37 by kamitsui         ###   ########.fr       */
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
int	checker(t_stack *stack_a, t_stack *stack_b)
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
			execute_instruction(type, stack_a, stack_b);
		else
			break ;
		ft_printf("%s %d", instruction, (int)type);// debug
		free(instruction);
	}
	if (is_sorted(stack_a) && is_empty(stack_b))
	{
		ft_printf("OK\n");
		return (0);
	}
	ft_printf("KO\n");
	return (1);
}
