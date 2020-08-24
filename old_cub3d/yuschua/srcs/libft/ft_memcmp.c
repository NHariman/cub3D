/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:26:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:56:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	if (n == 0)
		return (0);
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	i += 1;
	while (*ptr1 == *ptr2 && i < n)
	{
		ptr1 += 1;
		ptr2 += 1;
		i += 1;
	}
	return ((int)(*ptr1 - *ptr2));
}
