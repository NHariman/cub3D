/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 14:09:10 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:56:48 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[i] == 0)
		return (0);
	if (c == 0)
		return (1);
	while (s[i] == c && s[i] != '\0')
		i += 1;
	if (s[i] == 0)
		return (0);
	while (s[i] != '\0')
	{
		i += 1;
		if (s[i] == c)
		{
			while (s[i] == c && s[i] != '\0')
				i += 1;
			if (s[i] != '\0')
				j += 1;
		}
	}
	return (j + 1);
}

static int			ft_stringlen(char const *str, char c, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == c)
		i += 1;
	while (str[i] != '\0' && y > 0)
	{
		i += 1;
		if (str[i] == c)
			y -= 1;
		while (str[i] == c)
			i += 1;
	}
	while (str[i] != c && str[i] != '\0')
	{
		i += 1;
		j += 1;
	}
	return (j + 1);
}

static char			*ft_string(char *string, char const *str, char c, int y)
{
	int i;

	i = 0;
	while (str[i] == c)
		i += 1;
	while (str[i] != '\0' && y > 0)
	{
		i += 1;
		if (str[i] == c)
			y -= 1;
		while (str[i] == c)
			i += 1;
	}
	while (str[i] != c && str[i] != '\0')
	{
		string[y] = str[i];
		i += 1;
		y += 1;
	}
	string[y] = '\0';
	return (string);
}

static void			ft_clean(char **split, int y)
{
	while (y >= 0)
	{
		free(split[y]);
		y -= 1;
	}
	free(split);
}

char				**ft_split(char const *s, char c)
{
	char		**split;
	int			y;
	int			count;

	if (!s)
		return (0);
	y = 0;
	count = ft_count(s, c);
	split = (char**)malloc(sizeof(char*) * (count + 1));
	if (!split)
		return (0);
	while (y < count)
	{
		split[y] = (char*)malloc(sizeof(char) * ft_stringlen(s, c, y));
		if (!split[y])
		{
			ft_clean(split, y);
			return (0);
		}
		split[y] = ft_string(split[y], s, c, y);
		y += 1;
	}
	split[y] = 0;
	return (split);
}
