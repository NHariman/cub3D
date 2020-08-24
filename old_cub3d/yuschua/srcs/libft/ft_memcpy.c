/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:18:45 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:56:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		d += 1;
		s += 1;
		n -= 1;
	}
	return (dst);
}
