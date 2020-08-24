/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 09:48:32 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:54:20 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	res;
	int		sign;
	long	max;

	max = 9223372036854775807;
	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\n' || *str == '\v' || *str == '\f')
		str += 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str += 1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > (max / 10))
			return (sign > 0) ? (-1) : (0);
		res = res * 10 + (*str - '0');
		str += 1;
	}
	return (res * sign);
}
