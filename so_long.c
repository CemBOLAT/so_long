/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:44:12 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/22 00:44:30 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *str)
{
	write(1, "Error: ", 7);
	ft_printf("\033[31m%s\n\033",str);
	exit (0);
}

void	ft_argument_control(char **argv, int argc)
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
	fd = open("./img/background.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG BACKGROUND PATH!");
	fd = open("./img/exit.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG EXIT PATH!");
	fd = open("./img/player.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG PLAYER PATH!");
	fd = open("./img/wall.xpm",O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG WALL PATH!");
	game->images.collectibles_path = "./img/coin.xpm";
	game->images.exit_path = "./img/exit.xpm";
	game->images.background_path = "./img/background.xpm";
	game->images.player_path = "./img/player.xpm";
	game->images.wall_path = "./img/wall.xpm";
}

void	ft_map_control(char **argv)
{
	char *str;
	int fd;

	str = ft_strjoin("./map/",argv[1]);
	fd = open(str,O_RDONLY);	
	if (fd <= 0)
		ft_exit("WRONG MAP NAME! ");
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		ft_exit("Invalid argument Number!");
	ft_argument_control(argv, argc);
	ft_map_control(argv);
	ft_image_control(&game);
	//printf("%s",game.images.collectibles_path);
}
