/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 14:18:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:55:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long nb)
{
	size_t	size;

	if (nb == 0)
		return (nb + 1);
	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size += 1;
	}
	while (nb != 0)
	{
		nb /= 10;
		size += 1;
	}
	return (size);
}

static int	ft_min(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	long	nn;
	long	l;
	char	*str;

	nn = n;
	l = ft_len(nn);
	if (l == 0)
		l = 1;
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[l] = '\0';
	l -= 1;
	if (nn < 0)
		nn = -nn;
	while (l >= 0)
	{
		str[l] = (nn % 10) + '0';
		l -= 1;
		nn /= 10;
	}
	if (ft_min(n))
		str[0] = '-';
	return (str);
}
