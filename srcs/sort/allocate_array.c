/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:07:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/22 13:08:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <stdlib.h>

int	*allocate_array(int	size)
{
	int	*array_pointer;

	array_pointer = (int *)malloc(sizeof(int) * size);
	if (array_pointer == NULL)
		handle_error(ERR_MALLOC);
	return (array_pointer);
}
