/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:26:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/06 17:25:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/**
 * @brief ERR_NUM is the number of the error below.
 * Have Duplicates, Is not integer, More integers than arguments
 */
# define ERR_NUM	1

/**
 * @brief ERR_MALLOC is error number for malloc failure (only test code)
 */
# define ERR_MALLOC	2

/**
 * @brief ERR_POP is error number for pop failure (only test code)
 */
# define ERR_POP	3

/**
 * @brief ERR_PUSH is error number for push failure (only test code)
 */
# define ERR_PUSH	4

/**
 * @brief ERR_PEEK is error number for peekh failure (only test code)
 */
# define ERR_PEEK	5

/**
 * @brief MSG_ERR is output when the below error is detected.
 * Have Duplicates, Is not integer, More integers than arguments
 */
# define MSG_ERR\
	"Error\n"

/**
 * @brief MSG_ERR_MALLOC is error message for malloc failure (only in my test)
 */
# define MSG_ERR_MALLOC\
	"Error: Memory allocation failed.\n"

/**
 * @brief MSG_ERR_POP is error message for pop failure (only in my test)
 */
# define MSG_ERR_POP\
	"Error: Stack is empty, cannot pop\n"

/**
 * @brief ERR_PUSH is error message for push failure (only in my test)
 */
# define MSG_ERR_PUSH\
	"Error: Stack is full, cannot push"

/**
 * @brief ERR_PEEK is error message for peek failure (only in my test)
 */
# define MSG_ERR_PEEK\
	"Error: Stack is empty, cannot peek\n"

# define MSG_ERR_SWAP\
	"Error: Stack does not have enough elements to perform swap\n"

# define MSG_ERR_ROTATE\
	"Error: Stack is empty, cannot rotate\n"

# define MSG_ERR_REVERSE_ROTATE\
	"Error: Stack is empty, cannot reverse rotate\n"

# define MSG_IS_SORTED\
	"Note: Stack is already sorted\n"

/**
 * @brief エラー処理の関数（標準エラー出力とプロセス終了）
 */
void	handle_error(int error_code);

/**
 * @brief エラーメッセージ出力とexit(1)を行う関数
 */
void	ft_perror_exit(char *message);

#endif
