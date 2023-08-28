/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_less_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:25:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/28 15:26:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_less_than(int a, int b)
{
	if (a < b)
		return (true);
	else
		return (false);
}
