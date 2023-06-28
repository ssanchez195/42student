/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:21:15 by sergisan          #+#    #+#             */
/*   Updated: 2023/06/28 14:36:53 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putstr(char *string)
{
	while (string)
	{
		write(1, &string, 1);
		string++;
	}
}

void	ft_putnbr(int nb, int option)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb >= 10)
	{
		write(1, nb / 10, 1);
		ft_putnbr(nb % 10, option);
	}
	else if (nb < 0 && option == 1)
	{
		write(1, "-", 1);
		ft_putnbr(-nb, option);
	}
	else if (nb < 0 && option == 0)
		ft_putnbr(-nb, option);
	else
		write(1, nb + 48, 1);
}
