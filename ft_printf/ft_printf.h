/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:06:14 by sergisan          #+#    #+#             */
/*   Updated: 2023/06/28 14:35:24 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_lst
{
	int	neg;
	int	zero;
	int	point;
	int	width;
	int	precision;
}					t_lst;
int		ft_printf(char const *flags, ...);
void	ft_putnbr(int nb, int option);
char	*ft_putstr(char *str);

#endif