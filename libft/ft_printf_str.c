/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 17:31:04 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/14 00:44:34 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		pft_putchar_fd(char c, int fd, int *count)
{
	ssize_t output;

	output = 0;
	if (*count < 0)
		return ;
	output = write(fd, &c, 1);
	if (output < 0)
		*count = -1;
}

void		pft_putstr_fd(char *s, int fd, int *count)
{
	int		length;
	ssize_t	output;

	output = 0;
	if (*count < 0)
		return ;
	if (s)
	{
		length = ft_strlen(s);
		output = write(fd, s, length);
		if (output < 0)
			*count = -1;
	}
}

void		ft_print_char(const char c, int *count, t_flag *flags)
{
	if (!flags->dash && !flags->zero)
		ft_pad(flags->pad - 1, count);
	if (flags->zero && !flags->dash)
		ft_padzero(flags->pad - 1, count);
	pft_putchar_fd(c, 1, count);
	if (*count < 0)
		return ;
	*count = *count + 1;
	if (flags->dash)
		ft_pad(flags->pad - 1, count);
}

/*
** undefined behaviour if not a literal string is given,
** but (null) is printed because
** that's what the real printf does.
*/

void		ft_print_str(const char *str, int *count, t_flag *flags)
{
	size_t		i;
	size_t		strlen;

	if (!str)
		str = "(null)";
	i = 0;
	strlen = ((size_t)flags->pre < ft_strlen(str)) ?
				flags->pre : ft_strlen(str);
	if (!flags->dash && !flags->zero && flags->pad > 0)
		ft_pad(flags->pad - strlen, count);
	if (flags->zero && !flags->dash)
		ft_padzero(flags->pad - strlen, count);
	while (i < strlen)
	{
		pft_putchar_fd(str[i], 1, count);
		if (*count < 0)
			return ;
		i++;
	}
	*count = *count + strlen;
	if (flags->dash)
		ft_pad(flags->pad - strlen, count);
}
