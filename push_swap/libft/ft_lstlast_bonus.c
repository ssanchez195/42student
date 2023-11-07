/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:52:57 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/07 12:24:01 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	cont;

	size = ft_lstsize(lst);
	cont = 1;
	if (size == 0)
		return (NULL);
	while (cont != size)
	{
		lst = lst -> next;
		cont++;
	}
	return (lst);
}
