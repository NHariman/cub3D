/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:28:48 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:57:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	count = 0;
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (join == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*join = *s1;
		join += 1;
		s1 += 1;
		count += 1;
	}
	while (*s2 != '\0')
	{
		*join = *s2;
		join += 1;
		s2 += 1;
		count += 1;
	}
	*join = '\0';
	return (join - count);
}
