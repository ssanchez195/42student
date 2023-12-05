#include "so_long.h"

t_game_info	*read_map(char *map_file)
{
	t_game_info *map_memory;
	char		*map;

	map_memory = ft_calloc(1, sizeof(t_game_info));
	map = read_file(map_file, map_memory);
	map_memory->map_lines = ft_split(map, '\n');
	map_memory->map_heigth = 0;
	while (map_memory->map_lines[map_memory->map_heigth])
		map_memory->map_heigth++;
	map_memory->width = ft_strlen(map_memory->map_lines[0]);
	free(map);
	return (map_memory);
}

char	*read_file(char *map_file, t_game_info map_memory)
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
		emptyline_checker(row[i]);
		while (row[i++])
		{
			if (row[i] == 'C')
				map_memory->collectable = map_memory->collectable + 1;
		}
		strjoin_lite(save, row);
		free(row);
	}
	close(fd);
	return (row);
}

void	emptyline_checker(char c)
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
