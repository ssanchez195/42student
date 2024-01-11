/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:38 by sergisan          #+#    #+#             */
/*   Updated: 2023/05/25 13:14:31 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;
	void	*content;

	if (!lst)
		return (NULL);
	content = f(lst->content);
	new_list = ft_lstnew(content);
	if (!new_list)
		return (del(content), NULL);
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		new_list->next = ft_lstnew(content);
		if (!(new_list->next))
		{
			ft_lstclear(&save, del);
			return (del(content), NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (save);
}
