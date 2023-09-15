/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:10:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 18:50:03 by kamitsui         ###   ########.fr       */
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
#include "debug.h"
#include <fcntl.h>
int	g_fd_log;
int	g_flag_debug;

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
	int		data_a[BUFF_SIZE];
	int		data_b[BUFF_SIZE];
	size_t	size;

//----- debug code ----------
	g_fd_log = open_log("debug.log", O_TRUNC);
	g_flag_debug = DEBUG_ON;
//---------------------------

	if (argc < 2)
		return (1);
	init_stack(&stack_a, (char *)"a");
	init_stack(&stack_b, (char *)"b");
	size = count_elements(&argv[1]);
	if (size > BUFF_SIZE)
		allocate_data(&stack_a, &stack_b, size);
	else
	{
		stack_a.data = &data_a[0];
		stack_b.data = &data_b[0];
	}
	set_data(&stack_a, &argv[1], size);

//----- debug code ----------
	if (g_flag_debug == DEBUG_ON)
		debug_data(g_fd_log, &stack_a, &stack_b);
//---------------------------

	if (is_sorted(&stack_a) == false)
		sort(&stack_a, &stack_b, size);

//----- debug code ----------
	if (g_flag_debug == DEBUG_ON)
		debug_data(g_fd_log, &stack_a, &stack_b);
//---------------------------

	free_stack(&stack_a, &stack_b, size);

//----- debug code ----------
	if (g_flag_debug == DEBUG_ON)
		close (g_fd_log);
//---------------------------

	return (0);
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
////---------------------------
//
// スタックの状態出力
//
////----- debug code ----------
//	if (g_flag_debug == DEBUG_ON)
//		debug_data(g_fd_log, &stack_a, &stack_b);
////---------------------------
//
// fd_logのリソースを解放
//
////----- debug code ----------
//	if (g_flag_debug == DEBUG_ON)
//		close (g_fd_log);
////---------------------------
//
