/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_less_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:25:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/28 22:35:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_less_than.c
 * @brief Check if a is less than b
 */
#include <stdbool.h>

/**
 * @brief Check if a is less than b
 *
 * @param a is the smaller integer to compare
 * @param b is the larger integer to compare
 *
 * @return true: a < b  false: other
 */
bool	is_less_than(int a, int b)
{
	if (a < b)
		return (true);
	else
		return (false);
}
