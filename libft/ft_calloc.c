/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:42:39 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/07 12:24:15 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	memory = malloc(count * size);
	i = 0;
	if (!memory)
		return (memory);
	while (i < count * size)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
