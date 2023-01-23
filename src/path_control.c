/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:46:37 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/23 11:53:56 by cbolat           ###   ########.fr       */
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
	int	fd;

	fd = open("./img/coin.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG COIN PATH!");
	close(fd);
	fd = open("./img/background.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG BACKGROUND PATH!");
	close(fd);
	fd = open("./img/exit.xpm", O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG EXIT PATH!");
	close(fd);
	game->images.collectibles_path = "./img/coin.xpm";
	game->images.exit_path = "./img/exit.xpm";
	game->images.background_path = "./img/background.xpm";
}

void	ft_map_control(char **argv, t_game *game)
{
	char	*str;
	int		fd;

	str = ft_strjoin("./map/", argv[1]);
	fd = open(str, O_RDONLY);
	if (fd <= 0)
		ft_exit("WRONG MAP NAME! ");
	game->map.map_path = str;
}
