/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:59:13 by sergisan          #+#    #+#             */
/*   Updated: 2024/04/02 15:56:06 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "./../get_next_line/get_next_line.h"
# include "./../libft/libft.h"
# include "./../ft_printf/ft_printf.h"
# include "./../MLX42/include/MLX42/MLX42.h"
//# include <X11/X.h>
//# include <X11/keysym.h>

enum e_keycode
{
	KEY_UP = 87,
	KEY_DOWN = 83,
	KEY_LEFT = 65,
	KEY_RIGHT = 68,
	ESC = 256
};

typedef struct s_steve
{
	int		x_pos;
	int		y_pos;
	void	*armed_steve;
	void	*front;
	void	*back;
	void	*left;
	void	*right;
	void	*sprite;
}	t_steve;

typedef struct s_map
{
	char	**map_info;
	void	*enemy;
	int		end_gate_count;
	int		end_gate_x;
	int		end_gate_y;
	int		width;
	int		heigth;
	int		eye_count;
}	t_map;

typedef struct s_blocks
{
	void	*end_eye;
	void	*end_port;
	void	*lava;
	void	*floor;
	void	*gomu;
}	t_blocks;

typedef struct s_game_info
{
	t_steve		*steve;
	t_map		*map;
	t_blocks	*blocks;
	int			sword;
	int			enemy_count;
	int			row_count;
	int			collectable;
	int			heigth;
	int			width;
	int			pressed_key;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*back_ground_end;
	char		**player_pos;
	int			score;
}	t_gm_inf;

void		block_checker(void);
void		block_checker2(void);
void		block_checker3(void);
void		chest_checker(void);
void		file_checker(char *file);
void		map_checker(t_gm_inf *game, char *map_file);
void		load_images(t_gm_inf *game);
void		load_more_images(t_gm_inf *game);
void		char_checker(t_gm_inf *game);
void		size_checker(t_gm_inf *game);
void		player_checker(t_gm_inf *game);
void		wall_checker(t_gm_inf *game);
void		ender_eye_checker(t_gm_inf *game);
void		end_gate_checker(t_gm_inf *game);
void		destroy_images(t_gm_inf *game);
void		render_map(t_gm_inf *game);
void		mov_check(t_gm_inf *game, int key, int x_pos, int y_pos);
void		choose_sprite(t_gm_inf *game, int key);
void		check_enemy_move(t_gm_inf *game);
void		find_enemy(t_gm_inf *game, char side);
void		move_enemy(t_gm_inf *game, int y_pos, int x_pos, char side);
void		char_loader(char block, t_gm_inf *game, int pixels_x, int pixels_y);
void		close_game(t_gm_inf *game);
void		key_press(struct mlx_key_data key_data, void *game_aux);
void		read_map(t_gm_inf *map_memory, char *map_file);
void		empty_line_checker(char c);
void		do_move(t_gm_inf *game, int x_pos, int y_pos);
char		*strjoin_lite(char **str, char *str2);
char		*read_file(char *map_file, t_gm_inf *map_memory);
int			empty_block_checker(t_gm_inf *game, int y_pos, int x_pos);


#endif