/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:55:40 by sergisan          #+#    #+#             */
/*   Updated: 2024/03/13 19:58:05 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	file_checker(char *file)
{
	int	length;
	int	fd_checker;

	length = ft_strlen(file) - 1;
	if (file[length] != 'r' || file[length - 1] != 'e'
		|| file[length - 2] != 'b' || file[length - 3] != '.')
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

void	map_checker(t_game_info *game, char *map_file)
{
	game->map = read_map(map_file);
	load_images(game);
	char_checker(game);
	size_checker(game);
	player_checker(game);
	wall_checker(game);
	ender_eye_checker(game);
	end_gate_checker(game);
}

void	load_images(t_game_info *game)
{
	game->heigth = game->map->heigth * 64;
	game->width = game->map->width * 64;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, game->heigth, "Minecraft"); 
	game->steve = ft_calloc(1, sizeof(t_steve));
	game->steve->x_pos = 0;
	game->steve->y_pos = 0;
	game->steve->front = xlm_xpm_file_to_image(game->mlx_ptr, \
				"./images/front_steve.xpm", 0, 0);
	game->steve->back = xlm_xpm_file_to_image(game->mlx_ptr, \
				"./images/back_steve.xpm", 0, 0);
	game->steve->rigth = xlm_xpm_file_to_image(game->mlx_ptr, \
				"./images/right_steve.xpm", 0, 0);
	game->steve->left = xlm_xpm_file_to_image(game->mlx_ptr, \
				"./images/left_steve.xpm", 0, 0);
	game->blocks->op_end_portal = xlm_xpm_file_to_image(game->mlx_ptr \
				".images/open_end_portal.xpm", 0, 0);
	game->blocks->cl_end_portal = xlm_xpm_file_to_image(game->mlx_ptr \
				".images/closed_end_portal.xpm", 0, 0);
	game->blocks->lava = xlm_xpm_file_to_image(game->mlx_ptr \
				".images/lava.xpm", 0, 0);
	game->blocks->floor = xlm_xpm_file_to_image(game->mlx_ptr \
				".images/vacio.xpm", 0, 0);
	load_more_images(game);
}

void	load_more_images(t_game_info *game)
{
	game->blocks->end_eye = xlm_xpm_file_to_image(game->mlx_ptr \
				"./images/ender_eye.xpm", 0, 0);
	game->back_ground_end = xlm_xpm_file_to_image(game->mlx_ptr \
				"./images/wallpaper.xpm", 0, 0);
	game->steve->sword = xlm_xpm_file_to_image(game->mlx_ptr \
				"./images/sword_steve.xpm", 0, 0);
	game->blocks->chest = xlm_xpm_file_to_image(game->mlx_ptr \
				"./images/chest.xpm", 0, 0);
	game->blocks->op_chest = xlm_xpm_file_to_image(game->mlx_ptr \
				"./images/open_chest.xpm", 0, 0);
	game->map->enemy = xlm_xpm_file_to_image(game->mlx_ptr \
				"./images/creeper.xpm", 0, 0);
	game->score = 0;
	game->steve->sprite = game->steve->front;
	game->steve->sword = 0;
}

void	char_checker(t_game_info *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map->map_info[i])
	{
		j = 0;
		while (game->map->map_info[i][j])
		{
			if (game->map->map_info[i][j] != '0' &&
			game->map->map_info[i][j] != '1' &&
			game->map->map_info[i][j] != 'P' &&
			game->map->map_info[i][j] != 'C' &&
			game->map->map_info[i][j] != 'E' &&
			game->map->map_info[i][j] != 'D' &&
			game->map->map_info[i][j] != 'S')
			{
				printf("Los caracteres del mapa no son los correctos");
				close_game(game, "\n");
			}
			j++;
		}
		i++;
	}
}

void	size_checker(t_game_info *game)
{
	int	length;
	int	i;

	length = game->map->width;
	i = 0;
	while (game->map->map_info[i])
	{
		if (ft_strlen(game->map->map_info[i]) != length)
		{
			printf("Error. Los limites del mapa no son correctos");
			close_game(game, "\n");
		}
		i++;
	}
}

void	player_checker(t_game_info *game)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	while (game->map->map_info[i])
	{
		j = 0;
		while (game->map->map_info[i][j])
		{
			if (game->map->map_info[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		close_game(game, "Error. Debe haber 1 jugador");
}

void	wall_checker(t_game_info *game)
{
	int	i;

	i = 0;
	while (game->map->map_info[0][i])
	{
		if (game->map->map_info[0][i] != '1' ||
		game->map->map_info[game->map->heigth - 1][i] != '1')
		{
			printf("Error. El limite del mapa no tiene pared(lava)");
			close_game(game, "\n");
		}
		i++;
	}
	i = 0;
	while (game->map->map_info[i])
	{
		if (game->map->map_info[0][i] != '1' ||
		game->map->map_info[i][game->map->width - 1] != '1')
		{
			printf("Error. El limite del mapa no tiene pared(lava)");
			close_game(game, "\n");
		}
	}
}

void	ender_eye_checker(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map_info[i])
	{
		j = 0;
		while (game->map->map_info[i][j])
		{
			if (game->map->map_info[i][j] == 'C')
				game->map->eye_count += 1;
			j++;
		}
		i++;
	}
	if (game->map->eye_count < 1)
		close_game(game, "Error. No hay coleccionables(Ojo de ender)");
}

void	end_gate_checker(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map_info[i] || game->map->end_gate_count > 1)
	{
		j = 0;
		while (game->map->map_info[i][j])
		{
			if (game->map->map_info[i][j] == 'E')
				game->map->end_gate_count += 1;
			j++;
		}
		i++;
	}
	if (game->map->end_gate_count != 1)
	{
		printf("Error. El numero de portales del end es distinto de 1");
		close_game(game, "\n");
	}
}

void	close_game(t_game_info *game, char *message)
{
	int			i;

	i = 0;
	ft_printf("%s", message);
	destroy_images(game);
	while (game->map->map_info[i])
	{
		free(game->map->map_info[i]);
		i++;
	}
	free(game->map->map_info);
	free(game->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(1);
}

void	destroy_images(t_game_info *game)
{
	t_game_info	*copy;

	copy = game;
	mlx_destroy_image(copy->mlx_ptr, game->steve->sprite);
	mlx_destroy_image(copy->mlx_ptr, game->steve->front);
	mlx_destroy_image(copy->mlx_ptr, game->steve->back);
	mlx_destroy_image(copy->mlx_ptr, game->steve->right);
	mlx_destroy_image(copy->mlx_ptr, game->steve->left);
	mlx_destroy_image(copy->mlx_ptr, game->steve->sword);
	mlx_destroy_image(copy->mlx_ptr, game->blocks->closed_end_portal);
	mlx_destroy_image(copy->mlx_ptr, game->blocks->open_end_portal);
	mlx_destroy_image(copy->mlx_ptr, game->blocks->end_eye);
	mlx_destroy_image(copy->mlx_ptr, game->blocks->lava);
	mlx_destroy_image(copy->mlx_ptr, game->blocks->floor);
	mlx_destroy_image(copy->mlx_ptr, game->blocks->chest);
	mlx_destroy_image(copy->mlx_ptr, game->blocks->op_chest);
	mlx_destroy_image(copy->mlx_ptr, game->map->enemy);
	mlx_destroy_image(copy->mlx_ptr, game->back_ground_end);
}

void	render_map(t_game_info *game)
{
	int		i;
	int		j;
	int		pixels_x;
	int		pixels_y;
	char	*score;

	i = 0;
	y = 0;
	score = ft_itoa(game->score);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 0, 0, 0x000000FF, score);
	free (score);
	while (game->map->map_info[i])
	{
		x = 0;
		j = 0;
		while (game->map->map_info[i][j])
		{
			char_loader(game->map->map_info[i][j], game, pixels_x, pixels_y);
			x += 64;
		}
		y += 64;
		i++;
	}
}

void	char_loader(char block, t_game_info *game, int pixels_x, int pixels_y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->blocks->floor, pixels_x, pixels_y);
	if (block == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->lava, pixels_x, pixels_y);
	else if (block == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->blocks->end_eye, pixels_x, pixels_y);
	else if (block == 'D')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->map->enemy, pixels_x, pixels_y);
	else if (block = 'S')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->blocks->chest, pixels_x, pixels_y);
	else if (block = 's')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->blocks->op_chest, pixels_x, pixels_y);
	else if (block == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->blocks->cl_end_portal, pixels_x, pixels_y);
		game->map->end_gate_x = pixels_x;
		game->map->end_gate_y = pixels_y;
	}
	else if (block == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->steve->front, pixels_x, pixels_y);
		game->steve->x_pos = pixels_x;
		game->steve->y_pos = pixels_y;
	}
}

int	move_character(int key, t_game_info *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (key == ESC)
		close_game(game, "");
	else if (key == KEY_RIGHT)
		move_checker(game, key, game->steve->x_pos + 64, game->steve->y_pos);
	else if (key == KEY_LEFT)
		move_checker(game, key, game->steve->x_pos - 64, game->steve->y_pos);
	else if (key == KEY_UP)
		move_checker(game, key, game->steve->x_pos, game->steve->y_pos - 64);
	else if (key == KEY_DOWN)
		move_checker(game, key, game->steve->x_pos, game->steve->y_pos + 64);
	render_map(game);
	return (key);
}

void	move_checker(t_game_info *game, int key, int x_pos, int y_pos)
{
	if (game->map->map_info[y_pos / 64][x_pos / 64] == 'E'
		&& game->map->eye_count == 0)
	{
		ft_printf("%i\n", (game->score + 1));
		close_game(game, "GANASTE!");
	}
	if (game->map->map_info[y_pos / 64][x_pos / 64] != '1'
		&& game->map->map_info[y_pos / 64][x_pos / 64] != 'E')
	{
		choose_sprite(game, key);
		do_move(game, x_pos, y_pos);
		check_enemy_move(game);
		if (game->map->map_info[y_pos / 64][x_pos / 64] == 'D' && game->steve->sword == 0)
			close_game(game, "KABUM");
		else if (game->map->map_info[y_pos / 64][x_pos / 64] == 'D' && game->steve->sword == 1)
			game->map->map_info[y_pos / 64][x_pos / 64] = 'P';
		ft_printf("%i\n", game->score);
	}
}

void	choose_sprite(t_game_info *game, int key)
{
	if (key == KEY_UP)
		game->steve->sprite = game->steve->back;
	else if (key == KEY_DOWN)
	{
		if (game->steve->sword == 0)
			game->steve->sprite = game->steve->front;
		else
			game->steve->sprite = game->steve->sword_steve;
	}
	else if (key == KEY_LEFT)
		game->steve->sprite = game->steve->left;
	else if (key == KEY_RIGHT)
		game->steve->sprite = game->steve->rigth;
}

void	check_enemy_move(t_game_info *game);
{
	if (game->score % 7 == 0)
		find_enemy(game, 'D');
	else if (game->score % 5 == 0)
		find_enemy(game, 'U');
	else if (game->score % 3 == 0)
		find_enemy(game, 'L');
	else if (game->score % 2 == 0)
		find_enemy(game, 'R');
}

void	find_enemy(t_game_info *game, char side)
{
	int	x_pos;
	int	y_pos;

	y_pos = 64;
	x_pos = 64;
	while (game->map->map_info[y_pos][x_pos] != '\0')
	{
		x_pos = 64;
		while (game->map->map_info[y_pos][x_pos] != '\n')
		{
			if (game->map->map_info[y_pos][x_pos] == 'D')
				move_enemy(game, y_pos, x_pos, side);
			x_pos += 64;
		}
		y_pos += 64;
	}
}

void	move_enemy(t_game_info *game, int y_pos, int x_pos, char side)
{
	if (side == 'D' && empty_block_checker(game, (y_pos / 64) + 1, x_pos) == 1)
	{
		game->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game->map->map_info[(y_pos / 64) + 1][x_pos / 64] = 'D';
	}
	else if (side == 'U' && empty_block_checker(game, (y_pos / 64) - 1, x_pos) == 1)
	{
		game->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game->map->map_info[(y_pos / 64) - 1][x_pos / 64] = 'D';
	}
	else if (side == 'L' && empty_block_checker(game, y_pos, (x_pos / 64) - 1) == 1)
	{
		game->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game->map->map_info[y_pos / 64][(x_pos / 64) - 1] = 'D';
	}
	else if (side == 'R' && empty_block_checker(game, y_pos, (x_pos / 64) + 1) == 1)
	{
		game->map->map_info[y_pos / 64][x_pos / 64] = '0';
		game->map->map_info[y_pos / 64][(x_pos / 64) + 1] = 'D';
	}
}

int	empty_block_checker(t_game_info *game, int y_pos, int x_pos)
{
	if (game->map->map_info[y_pos][x_pos] != 'E'
	&& game->map->map_info[y_pos][x_pos] != '1'
	&& game->map->map_info[y_pos][x_pos] != 'C'
	&& game->map->map_info[y_pos][x_pos] != 'S')
	{
		return (1);
	}
	return (0);
}

void	do_move(t_game_info *game, int x_pos, int y_pos)
{
	if (game->map->map_info[y_pos][x_pos] == 'C')
	{
		game->map->eye_count -= 1;
		game->map->map_info[y_pos, x_pos] = '0';
	}
	if (game->map->map_info[y_pos][x_pos] == 'S')
	{
		game->steve->sword = 1;
		game->map->map_info[y_pos][x_pos] = 's';
	}
	game->map->map_info[game->steve->y_pos / 64][game->steve->x_pos / 64] = '0'
	game->map->map_info[game->map->end_gate_y][game->map->end_gate_x] = 'E';
	game->map->map_info[y_pos][x_pos] = 'P';
	game->score += 1;
}

int	main(int argc, char **argv)
{
	t_game_info	game;

	if (argc == 2)
	{
		block_checker();
		file_checker(argv[1]);
		map_checker(&game, argv[1]);
		render_map(&game);
		mlx_hook(game->win_ptr, 2, 1, move_character, &game);
		mlx_hook(game->win_ptr, 17, 0, close_game(game, ""), &game);
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_printf("Los argumentos no se han introducido correctamente");
	return (0);
}
