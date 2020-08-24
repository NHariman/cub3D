/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:39:28 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:57:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i) && i < len)
	{
		if (*needle == *(haystack + i))
		{
			j = 0;
			while ((*(haystack + i + j) == *(needle + j)) && (i + j < len))
			{
				j += 1;
				if (!(*(needle + j)))
					return ((char*)(haystack + i));
			}
		}
		i += 1;
	}
	return (NULL);
}
