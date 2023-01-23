/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_control2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:52:37 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/23 11:54:34 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_control_2(t_game *game)
{
	int	fd;

	fd = open("./img/player.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG PLAYER PATH!");
	close(fd);
	fd = open("./img/wall.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG WALL PATH!");
	close(fd);
	game->images.player_path = "./img/player.xpm";
	game->images.wall_path = "./img/wall.xpm";
}
