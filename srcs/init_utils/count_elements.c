/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:11:14 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 12:01:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file count_elements.c
 * @brief count number of elements data
 */
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief count number of elements data
 *
 * @param input[] include integers data
 *
 * @return number of elements data
 */
size_t	count_elements(char *input[])
{
	size_t	size;
	char	*token;
	char	*token_head;
	size_t	i;

	size = 0;
	i = 0;
	while (input[i] != NULL)
	{
		token_head = ft_strdup(input[i]);
		token = token_head;
		token = ft_strtok(token, " ");
		while (token != NULL)
		{
			size++;
			token = ft_strtok(NULL, " ");
		}
		free(token_head);
		i++;
	}
	return (size);
}
