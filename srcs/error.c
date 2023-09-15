/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:37:09 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 15:20:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error.c
 * @brief エラー検出時のエラー処理する関数
 */
#include "error.h"
#include "ft_printf.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

//デバッグ用
//#include "debug.h"// debug
//#include <fcntl.h>// debug

/**
 * @brief エラーメッセージを標準エラー出力する関数。(ヘルパー関数）
 *
 * @param error_code 出力させたいエラーメッセージに対するエラーコード
 */
static void	error_message(int error_code)
{
	static char	*msg[6] = {NULL, MSG_ERR, MSG_ERR_MALLOC, MSG_ERR_POP,
		MSG_ERR_PUSH, MSG_ERR_PEEK};

	ft_dprintf(STDERR_FILENO, msg[error_code]);
}
// disable when review
//	if (g_flag_debug == DEBUG_ON)// debug
//		ft_dprintf(g_fd_log, msg[error_code]);

/**
 * @brief エラー処理の関数（標準エラー出力とプロセス終了）
 * システムコールのエラーおよびerror.hで定義しているエラーに対する処理
 *
 * @param error_code エラー判定の内容(全てERR_NUM)
 * @note 終了ステータスは次のいずれか\n
 * errno:システムコール失敗時にセットされるエラー番号\n
 * 1:error.hで定義しているERR_NUMのエラー内容
 */
void	handle_error(int error_code)
{
	int	status;

	status = 1;
	if (errno != 0)
		status = errno;
	error_message(error_code);
	exit(status);
}

/**
 * @brief エラーメッセージ出力とexit(1)を行う関数
 *
 * @param message エラー出力に書かせるメッセージ
 */
void	ft_perror_exit(char *message)
{
	ft_dprintf(STDERR_FILENO, message);
	exit (1);
}
