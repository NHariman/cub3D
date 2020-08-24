/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 12:45:56 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:57:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		f;
	size_t		b;

	if (s1 == NULL || set == NULL)
		return (NULL);
	f = 0;
	while (ft_strchr(set, s1[f]))
		f += 1;
	b = ft_strlen(s1);
	if (f >= b)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[b - 1]))
		b -= 1;
	str = malloc(sizeof(char) * (b - f) + 1);
	if (str == NULL)
		return (str);
	ft_strlcpy(str, s1 + f, (b - f) + 1);
	return (str);
}
