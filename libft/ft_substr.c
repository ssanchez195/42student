/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:27:40 by sergisan          #+#    #+#             */
/*   Updated: 2023/04/26 13:45:50 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substring;
	unsigned int		i;
	unsigned int		length;

	i = 0;
	length = ft_strlen((char *)s);
	if (start > length)
	{
		substring = ft_calloc(1, sizeof(char));
		return (substring);
	}
	if (len > length - start)
		len = length - start;
	substring = ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (substring);
	while ((i < len) && s[start])
	{
		substring[i] = s[start];
		start++;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
