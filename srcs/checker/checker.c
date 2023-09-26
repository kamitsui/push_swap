/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:46:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:10:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"
#include "error.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdbool.h>

static int	check_and_free(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	result;

	result = (is_sorted(stack_a) && is_empty(stack_b));
	if (result == true)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (size > MAX_SIZE)
		free_stack(stack_a, stack_b);
	return (result == true);
}

/**
 * @brief checker function for push_swap
 *
 * @param stack_a 
 * @param stack_b
 *
 * @return 
 */
int	checker(t_stack *stack_a, t_stack *stack_b, int size)
{
	char				*instruction;
	enum e_instruction	type;
	int					result;

	while (true)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (instruction == NULL)
			break ;
		type = search_type_instruction(instruction);
		if (type != INST_ERROR)
			execute_instruction(type, stack_a, stack_b);
		else
		{
			handle_error(ERR_NUM);
			break ;
		}
		free(instruction);
	}
	result = check_and_free(stack_a, stack_b, size);
	if (result == true)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}
