/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:10:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 17:05:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"

void	sort_small(t_stack *src, t_stack *tmp, size_t size)
{
	if (size <= 2)
		sort_two_elements(src);
	else if (size <= 3)
		sort_three_elements(src);
	else
		sort_six_elements(src, tmp);
}
