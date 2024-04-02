/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:55:40 by sergisan          #+#    #+#             */
/*   Updated: 2024/04/02 17:53:30 by sergisan         ###   ########.fr       */
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
		ft_printf("Error\nLa extension del archivo debe ser .ber");
		exit(1);
	}
	fd_checker = open(file, O_RDWR);
	if (fd_checker == -1)
	{
		ft_printf("Error\nEl archivo no puede abrirse");
		close(fd_checker);
		exit(1);
	}
	close(fd_checker);
}

void	map_checker(t_gm_inf *game, char *map_file)
{
	read_map(game, map_file);
	load_images(game);
	char_checker(game);
	size_checker(game);
	player_checker(game);
	wall_checker(game);
	ender_eye_checker(game);
	end_gate_checker(game);
}

void	load_images(t_gm_inf *game)
{
	game->heigth = game->map->heigth * 64;
	game->width = game->map->width * 64;
	game->mlx_ptr = mlx_init(game->width, game->heigth, "So_long", 1);
	if (game->mlx_ptr == NULL)
		write (1, "Error\nHay un error en el mlx_init", 33);
	game->blocks = ft_calloc(1, sizeof(t_blocks));
	game->blocks->lava = mlx_texture_to_image(game->mlx_ptr, \
		(mlx_load_png("./images/lava.png")));
	game->blocks->floor = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/vacio.png")));
	game->blocks->end_eye = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/ender_eye.png")));
	game->back_ground_end = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/wallpaper.png")));
	game->blocks->gomu = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/gomu.png")));
	game->blocks->end_port = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/end_portal.png")));
	load_more_images(game);
}

void	load_more_images(t_gm_inf *game)
{
	game->steve = ft_calloc(1, sizeof(t_steve));
	game->steve->x_pos = 0;
	game->steve->y_pos = 0;
	game->steve->armed_steve = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/diamond_steve.png")));
	game->steve->front = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/front_steve.png")));
	game->steve->back = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/back_steve.png")));
	game->steve->right = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/right_steve.png")));
	game->steve->left = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/left_steve.png")));
	game->map->enemy = mlx_texture_to_image(game->mlx_ptr, \
				(mlx_load_png("./images/creeper.png")));
	game->score = 0;
	game->steve->sprite = game->steve->front;
	game->sword = 0;
}

void	char_checker(t_gm_inf *game)
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
				ft_printf("Error\nLos caracteres del mapa no son correctos\n");
				close_game(game);
			}
			j++;
		}
		i++;
	}
}

void	size_checker(t_gm_inf *game)
{
	int	length;
	int	i;

	length = game->map->width;
	i = 0;
	while (game->map->map_info[i])
	{
		if (ft_strlen(game->map->map_info[i]) != length)
		{
			printf("Error\nLos limites del mapa no son correctos\n");
			close_game(game);
		}
		i++;
	}
}

void	player_checker(t_gm_inf *game)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
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
	{
		ft_printf("Error\nDebe haber 1 jugador\n");
		close_game(game);
	}
}

void	wall_checker(t_gm_inf *game)
{
	int	i;

	i = 0;
	while (game->map->map_info[0][i])
	{
		if (game->map->map_info[0][i] != '1' ||
		game->map->map_info[game->map->heigth - 1][i] != '1')
		{
			printf("Error\nEl limite del mapa no tiene pared(lava)\n");
			close_game(game);
		}
		i++;
	}
	i = 0;
	while (game->map->map_info[i])
	{
		if (game->map->map_info[0][i] != '1' ||
		game->map->map_info[i][game->map->width - 1] != '1')
		{
			printf("Error\nEl limite del mapa no tiene pared(lava)\n");
			close_game(game);
		}
		i++;
	}
}

void	ender_eye_checker(t_gm_inf *game)
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
	{
		write(1, "Error\nNo hay ojo del end\n", 26);
		close_game(game);
	}
}

void	end_gate_checker(t_gm_inf *game)
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
		printf("Error\nEl numero de portales del end es distinto de 1\n");
		close_game(game);
	}
}

void	close_game(t_gm_inf *game)
{
	int				i;

	i = 0;
	destroy_images(game);
	while (game->map->map_info[i])
		free(game->map->map_info[i++]);
	free(game->map->map_info);
	//free(game->map);
	//mlx_close_window(game->mlx_ptr);
}

void	destroy_images(t_gm_inf *game)
{
	mlx_delete_texture(game->steve->front);
	mlx_delete_texture(game->steve->back);
	mlx_delete_texture(game->steve->right);
	mlx_delete_texture(game->steve->left);
	mlx_delete_texture(game->steve->armed_steve);
	mlx_delete_texture(game->blocks->end_port);
	mlx_delete_texture(game->blocks->end_eye);
	mlx_delete_texture(game->blocks->lava);
	mlx_delete_texture(game->blocks->floor);
	mlx_delete_texture(game->blocks->gomu);
	mlx_delete_texture(game->map->enemy);
	mlx_delete_texture(game->back_ground_end);
}

void	render_map(t_gm_inf *game)
{
	int		i;
	int		j;
	int		pixels_x;
	int		pixels_y;
	char	*score;

	i = 0;
	j = 0;
	pixels_y = 0;
	score = ft_itoa(game->score);
	mlx_put_string(game->mlx_ptr, score, 0, 0);
	free(score);
	while (game->map->map_info[i])
	{
		pixels_x = 0;
		j = 0;
		while (game->map->map_info[i][j])
		{
			char_loader(game->map->map_info[i][j], game, pixels_x, pixels_y);
			pixels_x += 64;
			j++;
		}
		pixels_y += 64;
		i++;
	}
}

void	char_loader(char block, t_gm_inf *game, int x, int y)
{
	mlx_image_to_window(game->mlx_ptr, game->blocks->floor, x, y);
	if (block == '1')
		mlx_image_to_window(game->mlx_ptr, game->blocks->lava, x, y);
	else if (block == 'C')
		mlx_image_to_window(game->mlx_ptr, game->blocks->end_eye, x, y);
	else if (block == 'D')
	{
		mlx_image_to_window(game->mlx_ptr, game->map->enemy, x, y);
		game->enemy_count += 1;
	}
	else if (block == 'S')
		mlx_image_to_window(game->mlx_ptr, game->blocks->gomu, x, y);
	else if (block == 'E')
	{
		mlx_image_to_window(game->mlx_ptr, game->blocks->end_port, x, y);
		game->map->end_gate_x = x;
		game->map->end_gate_y = y;
	}
	else if (block == 'P')
	{
		mlx_image_to_window(game->mlx_ptr, game->steve->sprite, x, y);
		game->steve->x_pos = x;
		game->steve->y_pos = y;
	}
}

void key_press(struct mlx_key_data key_data, void *game_aux)
{
	t_gm_inf	*game;
	int			pressed_key;
	int			norm_x;
	int			norm_y;

	game = game_aux;
	norm_x = game->steve->x_pos;
	norm_y = game->steve->y_pos;
	pressed_key = key_data.key;
	if (pressed_key == ESC)
		close_game(game);
	else if (pressed_key == KEY_RIGHT)
		mov_check(game, pressed_key, norm_x + 64, norm_y);
	else if (pressed_key == KEY_LEFT)
		mov_check(game, pressed_key, norm_x - 64, norm_y);
	else if (pressed_key == KEY_UP)
		mov_check(game, pressed_key, norm_x, norm_y - 64);
	else if (pressed_key == KEY_DOWN)
		mov_check(game, pressed_key, norm_x, norm_y + 64);
	render_map(game);
}

void	mov_check(t_gm_inf *game, int key, int x_pos, int y_pos)
{
	if (game->map->map_info[y_pos / 64][x_pos / 64] == 'E'
		&& game->map->eye_count == 0)
	{
		ft_printf("%i\n", (game->score + 1));
		close_game(game);
	}
	if (game->map->map_info[y_pos / 64][x_pos / 64] != '1'
		&& game->map->map_info[y_pos / 64][x_pos / 64] != 'E')
	{
		choose_sprite(game, key);
		if (game->enemy_count >= 1)
			check_enemy_move(game);
		if (game->map->map_info[y_pos / 64][x_pos / 64] == 'D' && game->sword == 0)
			close_game(game);
		else if (game->map->map_info[y_pos / 64][x_pos / 64] == 'D' && game->sword == 1)
			game->map->map_info[y_pos / 64][x_pos / 64] = 'P';
		do_move(game, x_pos / 64, y_pos / 64);
		ft_printf("%i\n", game->score);
	}
}

void	choose_sprite(t_gm_inf *game, int key)
{
	if (key == KEY_UP)
		game->steve->sprite = game->steve->back;
	else if (key == KEY_DOWN)
	{
		if (game->sword == 0)
			game->steve->sprite = game->steve->front;
		else
			game->steve->sprite = game->steve->armed_steve;
	}
	else if (key == KEY_LEFT)
		game->steve->sprite = game->steve->left;
	else if (key == KEY_RIGHT)
		game->steve->sprite = game->steve->right;
}

void	check_enemy_move(t_gm_inf *game)
{
	if (game->enemy_count >= 1)
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
}

void	find_enemy(t_gm_inf *game, char side)
{
	int	x_pos;
	int	y_pos;

	y_pos = 1;
	x_pos = 1;
	while (game->map->map_info[y_pos][x_pos] != '\0')
	{
		x_pos = 1;
		while (game->map->map_info[y_pos][x_pos] != '\n')
		{
			if (game->map->map_info[y_pos][x_pos] == 'D')
				move_enemy(game, y_pos, x_pos, side);
			x_pos += 1;
		}
		y_pos += 1;
	}
}

void	move_enemy(t_gm_inf *game, int y_pos, int x_pos, char side)
{
	game->map->map_info[y_pos][x_pos] = '0';
	if (side == 'D' && empty_block_checker(game, y_pos + 1, x_pos) == 1)
		game->map->map_info[y_pos + 1][x_pos] = 'D';
	if (side == 'U' && empty_block_checker(game, y_pos - 1, x_pos) == 1)
		game->map->map_info[y_pos - 1][x_pos] = 'D';
	if (side == 'L' && empty_block_checker(game, y_pos, x_pos - 1) == 1)
		game->map->map_info[y_pos][x_pos - 1] = 'D';
	if (side == 'R' && empty_block_checker(game, y_pos, x_pos + 1) == 1)
	{
		game->map->map_info[y_pos][x_pos + 1] = 'D';
	}
	if ((game->steve->x_pos / 64) == (x_pos)
		&& (game->steve->y_pos / 64) == (y_pos) && game->sword == 0)
	{
		close_game(game);
	}
}

int	empty_block_checker(t_gm_inf *game, int y_pos, int x_pos)
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

void	do_move(t_gm_inf *game, int x_pos, int y_pos)
{
	int	norm_helper_x;
	int	norm_helper_y;

	norm_helper_x = game->map->end_gate_x / 64;
	norm_helper_y = game->map->end_gate_y / 64;
	if (game->map->map_info[y_pos][x_pos] == 'C')
	{
		game->map->eye_count -= 1;
		game->map->map_info[y_pos][x_pos] = '0';
	}
	if (game->map->map_info[y_pos][x_pos] == 'S')
		game->sword = 1;
	game->map->map_info[game->steve->y_pos / 64][game->steve->x_pos / 64] = '0';
	game->map->map_info[norm_helper_y][norm_helper_x] = 'E';
	game->map->map_info[y_pos][x_pos] = 'P';
	game->score += 1;
}

int	main(int argc, char **argv)
{
	t_gm_inf	*game;

	if (argc == 2)
	{
		block_checker();
		file_checker(argv[1]);
		game = ft_calloc(1, sizeof(t_gm_inf));
		game->map = ft_calloc(1, sizeof(t_map));
		map_checker(game, argv[1]);
		render_map(game);
		mlx_key_hook(game->mlx_ptr, key_press, game);
		mlx_loop(game->mlx_ptr);
		mlx_terminate(game->mlx_ptr);
		//close_game(game);
		game = NULL;
		printf("---------------------");
	}
	else
		ft_printf("Error\nLos argumentos no se han introducido correctamente");
//	system(ft_void);
	return (0);
}
