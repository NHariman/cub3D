/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:14:32 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:54:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*r;

	i = 0;
	r = malloc(sizeof(char) * (count * size));
	if (r == 0)
		return (0);
	while (i < (count * size))
	{
		r[i] = 0;
		i += 1;
	}
	return ((void*)r);
}
