/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_number_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/29 12:09:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include "ft_printf.h"

#define STR1 "1 2 3 4 5 6 7 8 9 10 a "

int	main(void)
{
	char	input[1024];
	size_t	number;

	ft_strlcpy(input, STR1, ft_strlen(STR1));
	number = count_number_data(input);
	ft_printf("string [%s] is [%d] elements", input, number);
	return (0);
}
