/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:15:28 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 16:14:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"

void	init_count(t_count *count)
{
	count->less = 0;
	count->over = 0;
	count->min = 0;
}
