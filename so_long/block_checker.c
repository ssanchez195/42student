#include "so_long.h"

void block_checker(void)
{
	int	fd_ender_eye;
	int	fd_lava_block;
	int	fd_open_portal;
	int	fd_closed_portal;

	fd_ender_eye = open("./images/ender_eye.xpm", O_RDWR);
	fd_lava_block = open("./images/lava.xpm", O_RDWR);
	fd_open_portal = open("./images/open_end_portal.xpm", O_RDWR);
	fd_closed_portal = open("./images/closed_end_portal", O_RDWR);
	if (fd_ender_eye == -1 || fd_lava_block == -1 || fd_open_portal == -1 || fd_closed_portal == -1)
	{
		ft_printf("Falta de archivo XPM");
		close(fd_ender_eye);
		close(fd_lava_block);
		close(fd_open_portal);
		close(fd_closed_portal);
		exit(1);
	}
	block_checker2();
	close(fd_ender_eye);
	close(fd_lava_block);
	close(fd_open_portal);
	close(fd_closed_portal);
}

void	block_checker2(void)
{
	int fd_empty_block;
	int	creeper;
	int	back_ground;

	fd_empty_block = open("./images/vacio.xpm", O_RDWR);
	creeper =  open("./images/creeper.xpm", O_RDWR);
	back_ground = open("./images/wallpaper.xpm", O_RDWR);
	if (fd_empty_block == -1 || creeper == -1 || back_ground == -1)
	{
		ft_printf("Falta de archivo XPM");
		close(fd_empty_block);
		close(creeper);
		close(back_ground);
		exit(1);
	}
	block_checker3();
	close(fd_empty_block);
	close(creeper);
	close(back_ground);
}

void	block_checker3(void)
{
	int	back_steve;
	int	front_steve;
	int	left_steve;
	int	right_steve;

	back_steve  = open("./images/back_steve.xpm", O_RDWR);
	front_steve = open("./images/front_steve.xpm", O_RDWR);
	left_steve = open("./images/left_steve.xpm", O_RDWR);
	right_steve = open("./images/rigth_steve.xpm", O_RDWR);
	if (back_steve == -1 || front_steve == -1 || left_steve == -1 || right_steve == -1)
	{
		ft_printf("Falta de archivo XPM");
		close(back_steve);
		close(front_steve);
		close(left_steve);
		close(right_steve);
		exit(1);
	}
	chest_checker();
	close(back_steve);
	close(front_steve);
	close(left_steve);
	close(right_steve);
}

void	chest_checker(void)
{
	int	chest;
	int	op_chest;

	chest = open("./images/chest.xpm", O_RDWR);
	op_chest = open("./images/opened_chest.xpm", O_RDWR);
	if (chest == -1 || op_chest == -1)
	{
		ft_printf("Falta de archivo XPM");
		close(chest);
		close(op_chest);
		exit(1);
	}
	close(chest);
	close(op_chest);
}