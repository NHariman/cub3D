/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 08:56:31 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 15:55:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*null1;
	t_list	*list1;

	if (!lst)
		return (NULL);
	list1 = ft_lstnew((*f)(lst->content));
	if (!list1)
		return (NULL);
	null1 = list1;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&null1, ft_lstnew(f(lst->content)));
		if (!null1)
		{
			ft_lstclear(&list1, del);
			return (NULL);
		}
		null1 = null1->next;
	}
	return (list1);
}
