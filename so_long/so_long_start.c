#include "so_long.h"

void block_checker(void)
{
	//Las lineas dan mas de 25, pero podemos hacer 2 funciones y que de esta salte a la otra
	int	fd_ender_eye;
	int	fd_lava_block;
	int	fd_open_portal;
	int	fd_closed_portal;
	int	fd_empty_block;

	fd_ender_eye = open("./images/ender_eye.xpm", O_RDWR);
	fd_lava_block = open("./images/lava.xpm", O_RDWR);
	fd_open_portal = open("./images/open_end_portal.xpm", O_RDWR);
	fd_closed_portal = open("./images/closed_end_portal", O_RDWR);
	fd_empty_block = open("./images/empty_block.xpm", O_RDWR);
	if (fd_ender_eye == -1 || fd_lava_block == -1 || fd_open_portal == -1 || fd_closed_portal == -1 || fd_empty_block == -1)
	{
		ft_printf("Falta de archivo XPM");
		close(fd_ender_eye);
		close(fd_lava_block);
		close(fd_open_portal);
		close(fd_closed_portal);
		close(fd_empty_block);
		exit(1);
	}
	close(fd_ender_eye);
	close(fd_lava_block);
	close(fd_open_portal);
	close(fd_closed_portal);
	close(fd_empty_block);
}

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
	map_size_checker(game_info);
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
	game_info->window_ptr = mlx_new_window(game_info->mlx_ptr, game_info->width, game_info->heigth, "Minecraft"); 
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
}

void	map_size_control(t_game_info *game_info)
{
	int	length;
	int	i;

	length = game_info->map->width;
	i = 0;
	while (game_info->)
	{
		/* code */
	}
	

}
int	main(int argc, char **argv)
{
	t_game_info game_info;

	if (argc == 2)
	{
		block_checker();
		//character_checker();
		//El character_checker solo es necesario si introduzco sprites
		//Si no, el personaje puede mirarse en el block_checker
		file_checker(argv[1]);
		//El file_checker comprueba que la extension sea correcta
		//Y tambien que tengamos permisos para el archivo
		map_checker(&game_info, argv[1]);
		wlx_hook();
		wlx_hook();
		wlx_loop();
	}
	else
		ft_printf("Los argumentos no se han introducido correctamente");
	return (0);
}