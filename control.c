/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cembolat <cembolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:53:47 by cembolat          #+#    #+#             */
/*   Updated: 2023/01/22 19:02:22 by cembolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_argument_control(char **argv)
{
	int	len;
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + (len - 4), ".ber", 4) != 0)
		ft_exit("Invalid argument VALUE!");
}

void	ft_image_control(t_game *game)
{
	int fd;

	fd = open("./img/coin.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG COIN PATH!");
	close(fd);
	fd = open("./img/background.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG BACKGROUND PATH!");
	close(fd);
	fd = open("./img/exit.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG EXIT PATH!");
	close(fd);
	fd = open("./img/player.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG PLAYER PATH!");
	close(fd);
	fd = open("./img/wall.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG WALL PATH!");
	close(fd);
	game->images.collectibles_path = "./img/coin.xpm";
	game->images.exit_path = "./img/exit.xpm";
	game->images.background_path = "./img/background.xpm";
	game->images.player_path = "./img/player.xpm";
	game->images.wall_path = "./img/wall.xpm";
}

void	ft_map_control(char **argv, t_game *game)
{
	char *str;
	int fd;

	str = ft_strjoin("./map/",argv[1]);
	fd = open(str,O_RDONLY);	
	if (fd <= 0)
		ft_exit("WRONG MAP NAME! ");
	game->map.map_path = str;
}