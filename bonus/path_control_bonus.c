/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:46:37 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/27 13:58:09 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_argument_control(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + (len - 4), ".ber", 4) != 0)
		ft_exit("Invalid argument VALUE!");
}

void	ft_image_control(t_game *game)
{
	int	fd;
	int	fd2;

	fd = open("./textures/coin.xpm", O_RDONLY);
	fd2 = open("./textures/coinb.xpm", O_RDONLY);
	if (fd <= 0 || fd2 <= 0)
		ft_exit("WRONG COIN PATH!");
	close(fd);
	close(fd2);
	fd = open("./textures/background.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG BACKGROUND PATH!");
	close(fd);
	fd = open("./textures/exit.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG EXIT PATH!");
	close(fd);
	game->images.collectibles_path = "./textures/coin.xpm";
	game->images.collectibles_path_bonus = "./textures/coinb.xpm";
	game->images.exit_path = "./textures/exit.xpm";
	game->images.background_path = "./textures/background.xpm";
}

void	ft_image_control_2(t_game *game)
{
	int	fd;
	int	fd2;

	fd = open("./textures/playerb.xpm", O_RDONLY);
	fd2 = open("./textures/player.xpm", O_RDONLY);
	if (fd <= 0 || fd2 <= 0)
		ft_exit("WRONG PLAYER PATH!");
	close(fd);
	close(fd2);
	fd = open("./textures/enemyb.xpm", O_RDONLY);
	fd2 = open("./textures/enemy.xpm", O_RDONLY);
	if (fd <= 0 || fd2 <= 0)
		ft_exit("WRONG ENEMY PATH!");
	close(fd);
	close(fd2);
	fd = open("./textures/wall.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG WALL PATH!");
	close(fd);
	game->images.player_path_bonus = "./textures/playerb.xpm";
	game->images.player_path = "./textures/player.xpm";
	game->images.enemy_path = "./textures/enemyb.xpm";
	game->images.enemy_path_bonus = "./textures/enemy.xpm";
	game->images.wall_path = "./textures/wall.xpm";
}

void	ft_map_control(char **argv, t_game *game)
{
	char	*str;
	int		fd;

	str = ft_strjoin("./maps/", argv[1]);
	fd = open(str, O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG MAP NAME! ");
	game->map.map_path = str;
}
