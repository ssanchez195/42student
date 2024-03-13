/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:55:47 by sergisan          #+#    #+#             */
/*   Updated: 2024/03/13 19:55:22 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

t_game_info	*read_map(char *map_file)
{
	t_game_info	*map_memory;
	char		*map;

	map_memory = ft_calloc(1, sizeof(t_game_info));
	map = read_file(map_file, map_memory);
	map_memory->map->map_info = ft_split(map, '\n');
	map_memory->map->heigth = 0;
	while (map_memory->map->map_info[map_memory->heigth])
		map_memory->heigth++;
	while (map_memory->map->map_info[0][map_memory->map->width])
		map_memory->map->width++;
	free (map);
	return (map_memory);
}

char	*read_file(char *map_file, t_game_info *map_memory)
{
	char	*row;
	char	*save;
	int		fd;
	int		i;

	fd = open(map_file, O_RDONLY);
	save = NULL;
	row = get_next_line(fd);
	while (!row)
	{
		i = 0;
		row = get_next_line(fd);
		empty_line_checker(row[i]);
		while (row[i++])
		{
			if (row[i] == 'C')
				map_memory->collectable = map_memory->collectable + 1;
		}
		strjoin_lite(&save, row);
		free(row);
	}
	close(fd);
	return (row);
}

void	empty_line_checker(char c)
{
	if (c == '\n')
	{
		ft_printf("El mapa tiene una linea vacia");
		exit(1);
	}
}

void	strjoin_lite(char **str, char *str2)
{
	char	*copy;

	copy = *str;
	*str = ft_strjoin(copy, str2);
	if (copy)
		free (copy);
}
