/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:49:27 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/06 17:46:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "process.h"

static void	initialize_machine(t_sm *machine, va_list *ap)
{
	machine->state = LETTER;
	machine->ap = ap;
	ft_bzero((void *)&machine->buffer, (size_t)4096);
	machine->out = ft_strnew(1);
	if (machine->out == NULL)
	{
		machine->state = ERROR;
		return ;
	}
	ft_bzero((void *)machine->out, 1);
	machine->out_size = 0;
	machine->len = 0;
	machine->flag = 0x0;
	machine->width = 0;
	machine->prec = 0;
}

int	ft_printf(const char *input, ...)
{
	t_sm	machine;
	va_list	ap;

	va_start(ap, input);
	initialize_machine(&machine, &ap);
	process(input, &machine);
	if (machine.state != ERROR)
	{
		machine.out = join_to_out(machine.out, machine.buffer, machine.len);
		if (machine.out == NULL)
			return (-1);
		machine.out_size = write(1, machine.out, machine.out_size);
	}
	free(machine.out);
	va_end(ap);
	if (machine.state == ERROR)
		return (-1);
	return (machine.out_size);
}

int	ft_dprintf(int fd, const char *input, ...)
{
	t_sm	machine;
	va_list	ap;
	int		original_stdout_fd;

	original_stdout_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	va_start(ap, input);
	initialize_machine(&machine, &ap);
	process(input, &machine);
	if (machine.state != ERROR)
	{
		machine.out = join_to_out(machine.out, machine.buffer, machine.len);
		if (machine.out == NULL)
			return (-1);
		machine.out_size = write(1, machine.out, machine.out_size);
	}
	free(machine.out);
	va_end(ap);
	if (machine.state == ERROR)
		return (-1);
	if (dup2(original_stdout_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		return 1;
	}
	close(fd);
	return (machine.out_size);
}
