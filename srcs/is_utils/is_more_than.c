/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_more_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:25:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/14 18:56:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_more_than.c
 * @brief Check if a is more than b
 */
#include <stdbool.h>

/**
 * @brief Check if a is more than b
 *
 * @param a is the larger integer to compare
 * @param b is the smaller integer to compare
 *
 * @return true: a > b  false: other
 */
bool	is_more_than(int a, int b)
{
	if (a > b)
		return (true);
	else
		return (false);
}
