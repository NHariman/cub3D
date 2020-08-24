/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 09:11:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:55:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list*)malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->content = (void*)content;
	element->next = NULL;
	return (element);
}
