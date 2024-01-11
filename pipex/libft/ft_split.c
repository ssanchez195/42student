/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:43:06 by sergisan          #+#    #+#             */
/*   Updated: 2023/10/26 11:14:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_pointcount(char *s, char c)
{
	int	cont;
	
	cont = 0;
	if (!*s)
		return (1);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			cont++;
		while (*s != c && *s)
			s++;
		if (*s)
			s++;
	}
	cont++;
	return (cont);
}

static char	**ft_freememory(char **cutstring, int i)
{
	i--;
	while (i >= 0 && cutstring[i])
	{
		free(cutstring[i]);
		i--;
	}
	free(cutstring);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**cutstring;
	int		i;
	int		wordlength;

	cutstring = ((char **)ft_calloc(ft_pointcount((char *)s, c), 8));
	if (!s || !cutstring)
		return (0);
	i = -1;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c))
				wordlength = ft_strchr(s, c) - s;
			else
				wordlength = ft_strlen((char *)s);
			cutstring[++i] = ft_substr(s, 0, wordlength);
			if (!cutstring[i])
				return (ft_freememory(cutstring, i));
			s += wordlength;
		}
	}
	return (cutstring);
}
