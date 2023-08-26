/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:26:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/26 17:25:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MSG_ERR_MALLOC\
	"Error: Memory allocation failed.\n"

# define MSG_ERR_SETDATA\
	"Error: Duplicate integers are not allowed.\n"

# define MSG_ERR_POP\
	"Error: Stack is empty, cannot pop\n"

# define MSG_ERR_PUSH\
	"Error: Stack is full, cannot push"

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

#endif
