/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hexflags.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 18:38:45 by nhariman      #+#    #+#                 */
/*   Updated: 2020/06/08 19:11:49 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long			ft_hexlen(unsigned long n)
{
	long		len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void			ft_hexpadlen(unsigned long n, long *padlen, t_flag *flags)
{
	if (flags->dot && flags->pre < 0)
	{
		flags->pre = -1;
		flags->dot = 0;
	}
	if (flags->dot && flags->pre <= 0 && n == 0)
		*padlen = flags->pad;
	else if (flags->dot && n < 0)
	{
		if (flags->pre < ft_hexlen(-n))
			*padlen = flags->pad - ft_hexlen(n);
		else
			*padlen = flags->pad - ft_hexlen(n) - (flags->pre - ft_hexlen(-n));
	}
	else if (flags->dot && n >= 0)
	{
		if (flags->pre < ft_hexlen(n))
			*padlen = flags->pad - ft_hexlen(n);
		else
			*padlen = flags->pad - ft_hexlen(n) - (flags->pre - ft_hexlen(n));
	}
	else
		*padlen = flags->pad - ft_hexlen(n);
}

void				ft_hex(char c, unsigned long n, int *count, t_flag *flags)
{
	long	padlen;

	padlen = 0;
	ft_hexpadlen(n, &padlen, flags);
	if ((!flags->dash && !flags->zero) ||
		(!flags->dash && flags->zero && flags->dot))
		ft_pad(padlen, count);
	if (flags->zero && !flags->dash && flags->pre == -1)
		ft_padzero(padlen, count);
	if (flags->dot)
		ft_padzero(flags->pre - ft_hexlen(n), count);
	if (flags->pre != 0 || (flags->pre == 0 && n != 0))
		ft_print_hex(c, (unsigned long)n, count);
	if (*count < 0)
		return ;
	if (flags->dash)
		ft_pad(padlen, count);
}

void				ft_ptr(unsigned long n, int *count, t_flag *flags)
{
	long	padlen;

	padlen = 0;
	ft_hexpadlen(n, &padlen, flags);
	if ((!flags->dash && !flags->zero) ||
		(!flags->dash && flags->zero && flags->dot))
		ft_pad(padlen - 2, count);
	if (flags->zero && !flags->dash && flags->pre == -1)
		ft_padzero(padlen, count);
	pft_putstr_fd("0x", 1, count);
	if (*count < 0)
		return ;
	*count = *count + ft_strlen("0x");
	if (flags->dot)
		ft_padzero(flags->pre - ft_hexlen(n), count);
	if (flags->pre != 0 || (flags->pre == 0 && n != 0))
		ft_print_hex('p', (unsigned long)n, count);
	if (*count < 0)
		return ;
	if (flags->dash)
		ft_pad(padlen - 2, count);
}
