#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

enum keycode
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
	int 	y_pos;
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
	int		collectable;
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
	t_blocks 	*blocks;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*back_ground_end;
	char		**player_pos;
	int			score;
}	t_game_info;

void	block_checker(void);
void	block_checker2(void);
void	block_checker3(void);
void	chest_checker(void);
void	file_checker(void);
void	map_checker(t_game_info *game_info, char *map_file);
void	load_images(t_game_info *game_info);
void	load_more_images(t_game_info *game_info);
void	char_checker(t_game_info *game_info);
void	size_checker(t_game_info *game_info);
void	player_checker(t_game_info *game_info);
void	wall_checker(t_game_info *game_info);
void	ender_eye_checker(t_game_info *game_info);
void	end_gate_checker(t_game_info *game_info);
void	close_game(t_game_info *game_info, char *message);
void	destroy_images(t_game_info *game_info);
void	render_map(t_game_info *game_info);
void	char_loader(char block, t_game_info *game_info, int pixels_x, int pixels_y);
int		move_character(int key, t_game_info *game_info);
void	move_checker(t_game_info *game_info, int key, int x_pos, int y_pos);
void	choose_sprite(t_game_info *game_info, int key);
void	check_enemy_move(t_game_info *game_info);
void	find_enemy(t_game_info *game_info, char side);
void	move_enemy(t_game_info *game_info, int y_pos, int x_pos, char side);
int		empty_block_checker(t_game_info *game_info, int y_pos, int x_pos);
void	do_move(t_game_info *game_info, int x_pos, int y_pos);

#endif