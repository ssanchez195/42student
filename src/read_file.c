/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:55:47 by sergisan          #+#    #+#             */
/*   Updated: 2024/04/02 15:40:16 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	read_map(t_gm_inf *map_memory, char *map_file)
{
	char	*map;

	map = read_file(map_file, map_memory);
	map_memory->map->map_info = ft_split(map, '\n');
	map_memory->map->heigth = 0;
	map_memory->map->width = 0;
	while (map_memory->map->map_info[map_memory->map->heigth])
		map_memory->map->heigth++;
	while (map_memory->map->map_info[0][map_memory->map->width])
		map_memory->map->width++;
	free (map);
}

char	*read_file(char *map_file, t_gm_inf *map_memory)
{
	char	*row;
	char	*save;
	int		fd;
	int		i;

	fd = open(map_file, O_RDONLY);
	save = get_next_line(fd);
	row = get_next_line(fd);
	while (save && row)
	{
		i = 0;
		save = strjoin_lite(&save, row);
		empty_line_checker(row[i]);
		while (row[i])
		{
			if (row[i] == 'C')
				map_memory->collectable = map_memory->collectable + 1;
			i++;
		}
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
	free(row);
	return (save);
}

void	empty_line_checker(char c)
{
	if (c == '\n')
	{
		ft_printf("El mapa tiene una linea vacia");
		exit(1);
	}
}

char	*strjoin_lite(char **str, char *str2)
{
	char	*tmp;

	if (str == NULL)
		*str = ft_strdup(str2);
	else
	{
		tmp = *str;
		*str = ft_calloc(ft_strlen(tmp) + ft_strlen(str2) + 1, sizeof(char *));
		if (!*str)
			return (NULL);
		ft_strcpy(*str, tmp);
		ft_strcat(*str, str2);
		free(tmp);
	}
	return (*str);
}
