/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:19:58 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:56:57 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s;

	s = ((char *)malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (s != NULL)
		ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}
