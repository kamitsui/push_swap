/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_number_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:11:14 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 12:10:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

size_t	count_number_data(char *input)
{
	size_t	number;
	char	*token;

	token = ft_strdup(input);
	number = 0;
	token = ft_strtok(token, " ");
	while (token != NULL)
	{
		number++;
		token = ft_strtok(NULL, " ");
	}
	return (number);
}

