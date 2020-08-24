/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:18:43 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:57:11 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	ds;
	size_t	ss;

	count = 0;
	ds = ft_strlen(dst);
	ss = ft_strlen(src);
	if (ds >= dstsize)
		return (ss + dstsize);
	while (src[count] && (dstsize - 1 > count + ds))
	{
		dst[count + ds] = src[count];
		count++;
	}
	dst[count + ds] = '\0';
	return (ds + ss);
}
