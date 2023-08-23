/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:19:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/23 09:23:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief 命令 pa, pb : スタックsrcの先頭要素をdstへプッシュする
 *
 * @param dst : プッシュ先のスタック
 * @param src : プッシュ元のスタック
 */
void	push_data(t_stack *dst, t_stack *src)
{
	int	value;

	value = pop(src);
	push(dst, value);
	ft_printf("p%s\n", dst->name);
}
