/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:57:23 by sergisan          #+#    #+#             */
/*   Updated: 2023/05/17 17:58:34 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	long_dst;
	size_t	long_src;
	size_t	cont;

	long_dst = ft_strlen(dst);
	long_src = ft_strlen(src);
	if (dstsize <= long_dst)
		return (long_src + dstsize);
	cont = long_dst;
	while (*src && cont < (dstsize - 1))
		*(dst + cont++) = *src++;
	*(dst + cont) = '\0';
	return (long_dst + long_src);
}
