/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:36:15 by sergisan          #+#    #+#             */
/*   Updated: 2023/06/28 15:11:02 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	i = 0;
	va_start(arguments, str);
	while (str[i] != '\0')
	{
		count = 0;
		if (str[i] == '%')
		{
			count++;
			i++;
		}
		if (str[i] == '%' && count > 0)
			ft_putstr("%");
		else if (ft_strchr())
			ft_filter(str[i], arguments);
		i++;
	}
	return (count);
}

void	ft_filter(char c, va_list arguments)
{
	if (c == 'c' || c == 's')
		ft_putstr(va_arg(arguments, *char));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arguments, int));
	else if (c == 'u')
	{
		if ()
	}
}
