/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:12:05 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:57:20 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(const char *s)
{
	int length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}
