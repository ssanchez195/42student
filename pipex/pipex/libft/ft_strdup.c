/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:46:52 by sergisan          #+#    #+#             */
/*   Updated: 2023/04/26 16:33:49 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *) malloc(ft_strlen((char *)s1) + 1);
	if (!(s2))
		return (0);
	ft_memcpy(s2, s1, ft_strlen((char *)s1) + 1);
	return (s2);
}
