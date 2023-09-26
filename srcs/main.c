/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/26 13:55:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief main function of push swap (this program to sort integer values)
 */
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "init.h"
#include "sort.h"
#include "error.h"
#include "ft_printf.h"

//デバッグ用
//#include "debug.h"
//#include <fcntl.h>
//int	g_fd_log;
//int	g_flag_debug;

/**
 * @brief main function of push swap (this program to sort integer values)
 *
 * @param argc is number of integer values - 1
 * @param argv[] is array of integer-valued strings to sort
 *
 * @return 
 */
int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		data_a[MAX_SIZE];
	int		data_b[MAX_SIZE];
	size_t	size;

	if (argc < 2)
		return (EXIT_FAILURE);
	size = count_elements(&argv[1]);
	init_stack(&stack_a, &stack_b, size);
	if (size > MAX_SIZE)
		allocate_data(&stack_a, &stack_b, size);
	else
	{
		stack_a.data = &data_a[0];
		stack_b.data = &data_b[0];
	}
	set_data(&stack_a, &argv[1], size);
	if (is_sorted(&stack_a) == false)
		sort(&stack_a, &stack_b, size);
	if (size > MAX_SIZE)
		free_stack(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
//debug code

//リークのチェック
//----- debug code ----------
//	system("leaks push_swap");// for debug
//---------------------------

// デバッグログの保存ファイルを開く & デバッグON
//
////----- debug code ----------
//	g_fd_log = open_log("debug.log", O_TRUNC);
//	g_flag_debug = DEBUG_ON;
////	g_flag_debug = DEBUG_OFF;
////---------------------------

// スタックの状態出力
////----- debug code ----------
//	if (g_flag_debug == DEBUG_ON)
//		debug_data(g_fd_log, &stack_a, &stack_b);
////---------------------------

// fd_logのリソースを解放
////----- debug code ----------
//	if (g_flag_debug == DEBUG_ON)
//		close (g_fd_log);
////---------------------------
