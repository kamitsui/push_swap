/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_number_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 14:31:46 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include "ft_printf.h"

#define STR1 "1 2 3 4 5 6 7 8 9 10 a "

int	main(int argc, char *argv[])
{
	//char	input[1024];
	size_t	size;
	size_t	i;

	size = count_elements(&argv[1]);
	ft_printf("string ");
	i = 0;
	while (argv[i] != NULL)
	{
		ft_printf("[%s] ", argv[i]);
		i++;
	}
	ft_printf("is [%d] elements\n", (int)size);
	(void)argc;
	return (0);
}
