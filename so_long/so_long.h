#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_steve
{
	int		x_pos;
	int 	y_pos;
	void	*front;
	void	*back;
	void	*left;
	void	*rigth;
}	t_steve;

typedef struct s_map
{
	int		*collectable;
	int		width;
	int		heigth;
	int		eye_count;
}	t_map;

typedef struct s_blocks
{
	void	*op_end_portal;
	void	*cl_end_portal;
	void	*lava;
	void	*floor;
}	t_blocks;

typedef struct s_game_info
{
	t_steve		*steve;
	t_map		*map;
	t_blocks 	*blocks;
	void		*mlx_ptr;
	void		*window_ptr;
	void		*textures[5];
	char		**player_pos;
}	t_game_info;

#endif