/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 14:50:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

#define STR0 "0"
#define STR1 "12345"
#define STR2 "2147483647"
#define STR3 "2147483648"
#define STR4 "-2147483648"
#define STR5 "-2147483649"
#define STR6 "12345678901234567890"
#define NUM  8

int	main(void)
{
	static char	*str[NUM] = {STR0, STR1, STR2, STR3, STR4, STR5, STR6, NULL};
	bool		is_valid;
	size_t		i;

	i = 0;
	while (str[i] != NULL)
	{
		is_valid = ft_isint(str[i]);
		ft_printf("ft_isint(%s)  -> [%s]\n", str[i], is_valid ? "Yes" : "No");
		i++;
	}
	return (0);
}
