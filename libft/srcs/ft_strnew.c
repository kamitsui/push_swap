/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:08:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/24 14:08:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
//#include <stdio.h>//for debug code
//int	main(void)
//{
//	size_t	size = 514;
//
//	char *ret = ft_strnew(size);
//	for (size_t i = 0;i < size + 1;i++)
//		if (ret[i] != 0)
//			exit(1);
//	free(ret);
//	exit(0);
//}
//	char	*str = ft_strnew(42);
//	printf("str |%s|\n", str);
//}
//	printf("%zu:i\n", i);
