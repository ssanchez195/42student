/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:59:13 by sergisan          #+#    #+#             */
/*   Updated: 2024/03/13 19:43:03 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "./../get_next_line/get_next_line.h"
# include "./../libft/libft.h"
# include "./../ft_printf/ft_printf.h"
# include "./../mlx/mlx.h"
//# include <X11/X.h>
//# include <X11/keysym.h>

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

typedef struct s_steve
{
	int		sword;
	int		x_pos;
	int		y_pos;
	void	*front;
	void	*back;
	void	*left;
	void	*rigth;
	void	*sprite;
}	t_steve;

typedef struct s_map
{
	char	**map_info;
	int		enemy;
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
	void	*op_end_portal;
	void	*cl_end_portal;
	void	*lava;
	void	*floor;
	void	*chest;
	void	*op_chest;
}	t_blocks;

typedef struct s_game_info
{
	t_steve		*steve;
	t_map		*map;
	t_blocks	*blocks;
	int			collectable;
	int			heigth;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*back_ground_end;
	char		**player_pos;
	int			score;
}	t_game_info;

void		block_checker(void);
void		block_checker2(void);
void		block_checker3(void);
void		chest_checker(void);
void		file_checker(char *file);
void		map_checker(t_game_info *game, char *map_file);
void		load_images(t_game_info *game);
void		load_more_images(t_game_info *game);
void		char_checker(t_game_info *game);
void		size_checker(t_game_info *game);
void		player_checker(t_game_info *game);
void		wall_checker(t_game_info *game);
void		ender_eye_checker(t_game_info *game);
void		end_gate_checker(t_game_info *game);
void		close_game(t_game_info *game, char *message);
void		destroy_images(t_game_info *game);
void		render_map(t_game_info *game);
void		char_loader(char block, t_game_info *game, int pixels_x, int pixels_y);
int			move_character(int key, t_game_info *game);
void		move_checker(t_game_info *game, int key, int x_pos, int y_pos);
void		choose_sprite(t_game_info *game, int key);
void		check_enemy_move(t_game_info *game);
void		find_enemy(t_game_info *game, char side);
void		move_enemy(t_game_info *game, int y_pos, int x_pos, char side);
int			empty_block_checker(t_game_info *game, int y_pos, int x_pos);
void		empty_line_checker(char c);
void		do_move(t_game_info *game, int x_pos, int y_pos);
char		*read_file(char *map_file, t_game_info *map_memory);
void		strjoin_lite(char **str, char *str2);
t_game_info	*read_map(char *map_file);


#endif