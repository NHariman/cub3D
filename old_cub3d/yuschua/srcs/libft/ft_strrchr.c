/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:21:08 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:57:39 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = (0);
	while (*str)
	{
		if (*str == c)
			ptr = (char*)str;
		str += 1;
	}
	if (ptr)
		return (ptr);
	if (c == '\0')
		return ((char*)str);
	return (0);
}
