/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:31:13 by sergisan          #+#    #+#             */
/*   Updated: 2023/05/31 15:54:36 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	memory = malloc(count * size);
	if (!memory)
		return (memory);
	i = 0;
	while (i < (count * size))
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
