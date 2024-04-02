/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:53:40 by sergisan          #+#    #+#             */
/*   Updated: 2024/04/02 16:19:07 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	block_checker(void)
{
	int	ender_eye;
	int	lava_block;
	int	end_portal;
	int	diamond;

	diamond = open("./images/diamond_steve.png", O_RDONLY);
	ender_eye = open("./images/ender_eye.png", O_RDONLY);
	lava_block = open("./images/lava.png", O_RDONLY);
	end_portal = open("./images/end_portal.png", O_RDONLY);
	if (diamond == -1 || ender_eye == -1
		|| lava_block == -1 || end_portal == -1)
	{
		write(1, "Faltan archivos XPM\n", 20);
		close(ender_eye);
		close(lava_block);
		close(end_portal);
		exit(1);
	}
	block_checker2();
	close(ender_eye);
	close(lava_block);
	close(end_portal);
}

void	block_checker2(void)
{
	int	empty_block;
	int	creeper;
	int	back_ground;
	int	gomu;

	empty_block = open("./images/vacio.png", O_RDONLY);
	creeper = open("./images/creeper.png", O_RDONLY);
	back_ground = open("./images/wallpaper.png", O_RDONLY);
	gomu = open("./images/gomu.png", O_RDONLY);
	if (empty_block == -1 || creeper == -1 || back_ground == -1 || gomu == -1)
	{
		write(1, "Faltan archivos XPM2\n", 21);
		close(empty_block);
		close(creeper);
		close(back_ground);
		close(gomu);
		exit(1);
	}
	block_checker3();
	close(empty_block);
	close(creeper);
	close(back_ground);
	close(gomu);
}

void	block_checker3(void)
{
	int	back_steve;
	int	front_steve;
	int	left_steve;
	int	right_steve;

	back_steve = open("./images/back_steve.png", O_RDONLY);
	front_steve = open("./images/front_steve.png", O_RDONLY);
	left_steve = open("./images/left_steve.png", O_RDONLY);
	right_steve = open("./images/right_steve.png", O_RDONLY);
	if (back_steve == -1 || front_steve == -1 || left_steve == -1 || right_steve == -1)
	{
		write(1, "Faltan archivos XPM3\n", 21);
		close(back_steve);
		close(front_steve);
		close(left_steve);
		close(right_steve);
		exit(1);
	}
	close(back_steve);
	close(front_steve);
	close(left_steve);
	close(right_steve);
}
