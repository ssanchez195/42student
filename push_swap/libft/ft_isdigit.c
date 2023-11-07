/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:31:49 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/03 13:39:30 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	return (0);
}

int	ft_isnumber(int num)
{
	if (num >= -2147483648 && num <= 2147483647)
		return (0);
	return (1);
}
