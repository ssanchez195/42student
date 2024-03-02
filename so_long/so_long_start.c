#include "so_long.h"

void	file_checker(char *file)
{
	int	length;
	int	fd_checker;

	length = ft_strlen(file) - 1;
	if (file[length] != 'r' || file[length - 1] != 'e' || file[length - 2] != 'b' || file[length - 3] != '.')
	{
		ft_printf("La extension del archivo debe ser .ber");
		exit(1);
	}
	fd_checker = open(file, O_RDWR);
	if (fd_checker == -1)
	{
		ft_printf("El archivo no puede abrirse");
		close(fd_checker);
		exit(1);
	}
	close(fd_checker);
}

void	map_checker(t_game_info *game_info, char *map_file)
{
	game_info->map = read_map(map_file);
	load_images(game_info);
	char_checker(game_info);
	size_checker(game_info);
	player_checker(game_info);
	wall_checker(game_info);
	ender_eye_checker(game_info);
	end_gate_checker(game_info);
}

void	load_images(t_game_info *game_info)
{
	game_info->heigth = game_info->map->heigth * 64;
	game_info->width = game_info->map->width * 64;
	game_info->mlx_ptr = mlx_init();
	game_info->win_ptr = mlx_new_window(game_info->mlx_ptr, game_info->width, game_info->heigth, "Minecraft"); 
	game_info->steve = ft_calloc(1, sizeof(t_steve));
	game_info->steve->x_pos = 0;
	game_info->steve->y_pos = 0;
	game_info->steve->front = xlm_xpm_file_to_image(game_info->mlx_ptr, \
				"./images/front_steve.xpm", 0, 0);
	game_info->steve->back = xlm_xpm_file_to_image(game_info->mlx_ptr, \
				"./images/back_steve.xpm", 0, 0);
	game_info->steve->rigth = xlm_xpm_file_to_image(game_info->mlx_ptr, \
				"./images/right_steve.xpm", 0, 0);
	game_info->steve->left = xlm_xpm_file_to_image(game_info->mlx_ptr, \
				"./images/left_steve.xpm", 0, 0);
	game_info->blocks->op_end_portal = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/open_end_portal.xpm", 0, 0);
	game_info->blocks->cl_end_portal = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/closed_end_portal.xpm", 0, 0);
	game_info->blocks->lava = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/lava.xpm", 0, 0);
	game_info->blocks->floor = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/vacio.xpm", 0, 0);
	load_more_images(game_info);
}

void	load_more_images(t_game_info *game_info)
{
	game_info->blocks->end_eye = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/ender_eye.xpm", 0, 0);
	game_info->back_ground_end = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/wallpaper.xpm", 0, 0);
	game_info->steve->sword_steve = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/sword_steve.xpm", 0, 0);
	game_info->blocks->chest = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/chest.xpm", 0, 0);
	game_info->blocks->op_chest = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/open_chest.xpm", 0, 0);
	game_info->map->enemy = xlm_xpm_file_to_image(game_info->mlx_ptr \
				".images/creeper.xpm", 0, 0);
	game_info->steve->score = 0;
	game_info->steve->sprite = game_info->steve->front;
	game_info->steve->sword = 0;
}

void	char_checker(t_game_info *game_info)
{
	int		i;
	int		j;

	i = 0;
	while (game_info->map->map_info[i])
	{
		j = 0;
		while (game_info->map->map_info[i][j])
		{
			if (game_info->map->map_info[i][j] != '0' &&
			game_info->map->map_info[i][j] != '1' &&
			game_info->map->map_info[i][j] != 'P' &&
			game_info->map->map_info[i][j] != 'C' &&
			game_info->map->map_info[i][j] != 'E' &&
			game_info->map->map_info[i][j] != 'D' &&
			game_info->map->map_info[i][j] != 'S')
			{
				close_game(game_info, "Los caracteres del mapa no son los correctos");
			}
			j++;
		}
		i++;
	}
}

void	size_checker(t_game_info *game_info)
{
	int	length;
	int	i;

	length = game_info->map->width;
	i = 0;
	while (game_info->map->map_info[i])
	{
		if (ft_strlen(game_info->map->map_info[i]) != length)
			close_game(game_info, "Error. Los limites del mapa no son correctos");
		i++;
	}
}

void	player_checker(t_game_info *game_info)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	while (game_info->map->map_info[i])
	{
		j = 0;
		while (game_info->map->map_info[i][j])
		{
			if (game_info->map->map_info[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		close_game(game_info, "Error. Debe haber 1 jugador");
}

void	wall_checker(t_game_info *game_info)
{
	int	i;

	i = 0;
	while (game_info->map->map_info[0][i])
	{
		if (game_info->map->map_info[0][i] == != '1' ||
		game_info->map->map_info[game_info->map->heigth - 1][i] != '1')
		{
			close_game(game_info, "Error. El limite del mapa no tiene pared(lava)");
		}
		i++;
	}
	i = 0;
	while (game_info->map->map_info[i])
	{
		if (game_info->map->map_info[0][i] != '1' ||
		game_info->map->map_info[i][game_info->map->width - 1] != '1')
		{
			close_game(game_info, "Error. El limite del mapa no tiene pared(lava)");
		}
	}
}

void	ender_eye_checker(t_game_info *game_info)
{
	int	i;
	int	j;

	i = 0;
	while (game_info->map->map_info[i])
	{
		j = 0;
		while (game_info->map->map_info[i][j])
		{
			if (game_info->map->map_info[i][j] == 'C')
				game_info->map->eye_count += 1;
			j++;
		}
		i++;
	}
	if (game_info->map->eye_count < 1)
		close_game(game_info, "Error. No hay coleccionables(Ojo de ender)");
}

void	end_gate_checker(t_game_info *game_info)
{
	int	i;
	int	j;
	
	i = 0;
	while (game_info->map->map_info[i] || game_info->map->end_gate_count > 1)
	{
		j = 0;
		while (game_info->map->map_info[i][j])
		{
			if (game_info->map->map_info[i][j] == 'E')
				game_info->map->end_gate_count += 1;
			j++;
		}
		i++;
	}
	if (game_info->map->end_gate_count != 1)
		close_game(game_info, "Error. El numero de portales del end es distinto de 1");
}

void	close_game(t_game_info *game_info, char *message)
{
	int			i;

	i = 0;
	ft_printf("%s", message);
	destroy_images(game_info);
	while (game_info->map->map_info[i])
	{
		free(game_info->map->map_info[i]);
		i++;
	}
	free(game_info->map->map_info);
	free(game_info->map);
	mlx_destroy_window(game_info->mlx_ptr, game_info->win_ptr);
	exit(1);
}

void	destroy_images(t_game_info *game_info)
{
	t_game_info *copy;

	copy = game_info;
	mlx_destroy_image(copy->mlx_ptr, game_info->steve->sprite);
	mlx_destroy_image(copy->mlx_ptr, game_info->steve->front_steve);
	mlx_destroy_image(copy->mlx_ptr, game_info->steve->back_steve);
	mlx_destroy_image(copy->mlx_ptr, game_info->steve->right_steve);
	mlx_destroy_image(copy->mlx_ptr, game_info->steve->back_steve);
	mlx_destroy_image(copy->mlx_ptr, game_info->steve->sword);
	mlx_destroy_image(copy->mlx_ptr, game_info->blocks->closed_end_portal);
	mlx_destroy_image(copy->mlx_ptr, game_info->blocks->open_end_portal);
	mlx_destroy_image(copy->mlx_ptr, game_info->blocks->end_eye);
	mlx_destroy_image(copy->mlx_ptr, game_info->blocks->lava);
	mlx_destroy_image(copy->mlx_ptr, game_info->blocks->floor);
	mlx_destroy_image(copy->mlx_ptr, game_info->blocks->chest);
	mlx_destroy_image(copy->mlx_ptr, game_info->blocks->op_chest);
	mlx_destroy_image(copy->mlx_ptr, game_info->map->enemy);
	mlx_destroy_image(copy->mlx_ptr, game_info->back_ground_end);
}

void	render_map(t_game_info *game_info)
{
	int		i;
	int		j;
	int		pixels_x;
	int		pixels_y;
	char	*score;

	i = 0;
	y = 0;
	score = ft_itoa(game_info->score);
	mlx_string_put(game_info->mlx_ptr, game_info->win_ptr, 0, 0, 0x000000FF, score);
	free (score);
	while (game_info->map->map_info[i])
	{
		x = 0;
		j = 0;
		while (game_info->map->map_info[i][j])
		{
			char_loader(game_info->map->map_info[i][j], game_info, pixels_x, pixels_y);
			x += 64;
		}
		y += 64;
		i++;
	}
}

void	char_loader(char block, t_game_info *game_info, int pixels_x, int pixels_y)
{
	mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->blocks->floor, pixels_x, pixels_y);
	if (block == '1')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->lava, pixels_x, pixels_y);
	else if (block == 'C')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->blocks->end_eye, pixels_x, pixels_y);
	else if (block == 'D')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->map->enemy, pixels_x, pixels_y);
	else if (block = 'S')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->blocks->chest, pixels_x, pixels_y);
	else if (block = 's')
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->blocks->op_chest, pixels_x, pixels_y);
	else if (block == 'E')
	{
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->blocks->cl_end_portal, pixels_x, pixels_y);
		game_info->map->end_gate_x = pixels_x;
		game_info->map->end_gate_y = pixels_y;
	}
	else if (block == 'P')
	{
		mlx_put_image_to_window(game_info->mlx_ptr, game_info->win_ptr, game_info->steve->front, pixels_x, pixels_y);
		game_info->steve->x_pos = pixels_x;
		game_info->steve->y_pos = pixels_y;
	}
}

int	move_character(int key, t_game_info *game_info)
{
	mlx_clear_window(game_info->mlx_ptr, game_info->win_ptr);
	if (key == ESC)
		close_game(game_info, "");
	else if (key == KEY_RIGHT)
		move_checker(game_info, key, game_info->steve->x_pos + 64, game_info->steve->y_pos);
	else if (key == KEY_LEFT)
		move_checker(game_info, key, game_info->steve->x_pos - 64, game_info->steve->y_pos);
	else if (key == KEY_UP)
		move_checker(game_info, key, game_info->steve->x_pos, game_info->steve->y_pos - 64);
	else if (key == KEY_DOWN)
		move_checker(game_info, key, game_info->steve->x_pos, game_info->steve->y_pos + 64);
	render_map(game_info);
	return (key);
}

void	move_checker(t_game_info *game_info, int key, int x_pos, int y_pos)
{
	if (game_info->map->map_info[y_pos / 64][x_pos / 64] == 'E'
		&& game_info->map->eye_count == 0)
	{
		ft_printf("%i\n", (game_info->score + 1));
		close_game(game_info, "GANASTE!");
	}
	if (game_info->map->map_info[y_pos / 64][x_pos / 64] != '1'
		&& game_info->map->map_info[y_pos / 64][x_pos / 64] != 'E')
	{
		choose_sprite(game_info, key);
		do_move(game_info, x_pos, y_pos);
		check_enemy_move(game_info);
		if (game_info->map->map_info[y_pos / 64][x_pos / 64] == 'D' && game_info->steve->sword == 0)
			close_game(game_info, "KABUM");
		else if (game_info->map->map_info[y_pos / 64][x_pos / 64] == 'D' && game_info->steve->sword == 1)
			game_info->map->map_info[y_pos / 64][x_pos / 64] = 'P';
		ft_printf("%i\n", game_info->score);
	}
}

void	choose_sprite(t_game_info *game_info, int key)
{
		if (key == KEY_UP)
			game_info->steve->sprite = game_info->steve->back
		else if (key == KEY_DOWN)
		{
			if (game_info->steve->sword == 0)
				game_info->steve->sprite = game_info->steve->front;
			else
				game_info->steve->sprite = game_info->steve->sword_steve;
		}
		else if (key == KEY_LEFT)
			game_info->steve->sprite = game_info->steve->left;
		else if (key == KEY_RIGHT)
			game_info->steve->sprite = game_info->steve->rigth;
}

void	check_enemy_move(t_game_info *game_info);
{
	if (game_info->score % 7 == 0)
		find_enemy(game_info, 'D');
	else if (game_info->score % 5 == 0)
		find_enemy(game_info, 'U');
	else if (game_info->score % 3 == 0)
		find_enemy(game_info, 'L');
	else if (game_info->score % 2 == 0)
		find_enemy(game_info, 'R');
}

void	find_enemy(t_game_info *game_info, char side)
{
	int	x_pos;
	int	y_pos;

	y_pos = 64;
	x_pos = 64;
	while (game_info->map->map_info[y_pos][x_pos] != '\0')
	{
		x_pos = 64;
		while (game_info->map->map_info[y_pos][x_pos] != '\n')
		{
			if (game_info->map->map_info[y_pos][x_pos] == 'D')
				move_enemy(game_info, y_pos, x_pos, side);
			x_pos += 64;
		}
		y_pos += 64;
	}
}

void	move_enemy(t_game_info *game_info, int y_pos, int x_pos, char side)
{
	if (side == 'D' && empty_block_checker(game_info, (y_pos / 64) + 1, x_pos) == 1)
	{
		game_info->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game_info->map->map_info[(y_pos / 64) + 1][x_pos / 64] = 'D';
	}
	else if (side == 'U' && empty_block_checker(game_info, (y_pos / 64) - 1, x_pos) == 1)
	{
		game_info->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game_info->map->map_info[(y_pos / 64) - 1][x_pos / 64] = 'D';
	}
	else if (side == 'L' && empty_block_checker(game_info, y_pos, (x_pos / 64) - 1) == 1)
	{
		game_info->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game_info->map->map_info[y_pos / 64][(x_pos / 64) - 1] = 'D';
	}
	else if (side == 'R' && empty_block_checker(game_info, y_pos, (x_pos / 64) + 1) == 1)
	{
		game_info->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game_info->map->map_info[y_pos / 64][(x_pos / 64) + 1] = 'D';
	}
}

int	empty_block_checker(t_game_info *game_info, int y_pos, int x_pos)
{
	if (game_info->map->map_info[y_pos][x_pos] != 'E'
	&& game_info->map->map_info[y_pos][x_pos] != '1'
	&& game_info->map->map_info[y_pos][x_pos] != 'C'
	&& game_info->map->map_info[y_pos][x_pos] != 'S')
	{
		return (1);
	}
	return (0);
}

void	do_move(t_game_info *game_info, int x_pos, int y_pos)
{
	if (game_info->map->map_info[y_pos][x_pos] == 'C')
	{
		game_info->map->eye_count -= 1;
		game_info->map->map_info[y_pos, x_pos] = '0';
	}
	if (game_info->map->map_info[y_pos][x_pos] == 'S')
	{
		game_info->steve->sword = 1;
		game_info->map->map_info[y_pos][x_pos] = 's';
	}
	game_info->map->map_info[game_info->steve->y_pos / 64][game_info->steve->x_pos / 64] = '0'
	game_info->map->map_info[game_info->map->end_gate_y][game_info->map->end_gate_x] = 'E';
	game_info->map->map_info[y_pos][x_pos] = 'P';
	game_info->score += 1;
}

int	main(int argc, char **argv)
{
	t_game_info game_info;

	if (argc == 2)
	{
		block_checker();
		file_checker(argv[1]);
		map_checker(&game_info, argv[1]);
		render_map(&game_info);
		mlx_hook(game_info->win_ptr, 2, 1, move_character, &game_info);
		mlx_hook(game_info->win_ptr, 17, 0, close_game(game_info, ""), &game_info);
		mlx_loop(game_info->mlx_ptr);
	}
	else
		ft_printf("Los argumentos no se han introducido correctamente");
	return (0);
}