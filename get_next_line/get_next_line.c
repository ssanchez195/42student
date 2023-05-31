/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:31:06 by sergisan          #+#    #+#             */
/*   Updated: 2023/05/31 16:02:37 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Tengo que mirar si funciona al final porque en el tutorial pone:
//char *get_next_line(int fd) y yo tengo un int get_next_line(int fd)

char	*ft_get_line(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = ft_calloc(ft_strlen(save), sizeof(char *));
	if (!str)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;

}

char	*ft_save(char *save)
{

}

char	*ft_read_and_save(int fd, char *save)
{
	
}

int	get_next_line(int fd)
{
	
}
