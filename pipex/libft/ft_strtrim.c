/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:49:26 by sergisan          #+#    #+#             */
/*   Updated: 2023/05/03 14:53:53 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getinit(const char *s1, const char *s2)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen((char *)s1);
	while (i < length)
	{
		if (ft_strchr(s2, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_getlast(const char *s1, const char *s2)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen((char *)s1);
	while (i < length)
	{
		if (ft_strchr(s2, s1[length - i - 1]) == 0)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		init;
	int		last;
	int		cont;
	char	*strcut;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	init = ft_getinit(s1, set);
	last = ft_getlast(s1, set);
	cont = ft_strlen((char *)s1) - init - last + 1;
	if (init == ft_strlen((char *)s1))
	{
		strcut = ft_calloc(1, sizeof(char));
		return (strcut);
	}
	strcut = ft_calloc(cont, sizeof(char));
	if (!strcut)
		return (strcut);
	ft_strlcpy(strcut, ((char *)s1) + init, (unsigned)cont);
	return (strcut);
}
