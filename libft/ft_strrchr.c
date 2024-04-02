/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:55:43 by sergisan          #+#    #+#             */
/*   Updated: 2024/03/23 19:10:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*init;

	init = (char *)s;
	i = ft_strlen(s);
	s = (s + i);
	if (c > 256)
		c = c % 256;
	while (s > init && c != *s)
		s--;
	if (c == *s)
		return ((char *)s);
	return (0);
}
