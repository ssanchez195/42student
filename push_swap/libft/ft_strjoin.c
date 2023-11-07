/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:20:05 by sergisan          #+#    #+#             */
/*   Updated: 2023/05/31 12:15:21 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	int		count;
	int		count2;
	char	*stringjoin;

	length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	stringjoin = ft_calloc(length + 1, 1);
	if (!stringjoin)
		return (stringjoin);
	count = 0;
	count2 = 0;
	while (count < ft_strlen((char *)s1))
	{
		stringjoin[count] = s1[count];
		count++;
	}
	while (count2 < ft_strlen((char *)s2))
	{
		stringjoin[count] = s2[count2];
		count++;
		count2++;
	}
	return ((char *)stringjoin);
}
