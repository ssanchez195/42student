/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:56:37 by sergisan          #+#    #+#             */
/*   Updated: 2023/05/11 12:15:12 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*content2;

	content2 = malloc (sizeof(t_list));
	if (!content2)
		return (NULL);
	content2 -> content = content;
	content2 -> next = NULL;
	return (content2);
}
