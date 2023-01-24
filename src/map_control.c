/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:46:42 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/24 12:47:33 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rectangular_control(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map.map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_exit ("GET NEXT LINE IS BROKEN !");
	game->map.width = ft_strlen(line);
	game->map.height = 0;
	while (1)
	{
//		free(line);
		game->map.height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\0')
			break ;
		if (game->map.width != (int)ft_strlen(line) && line[0] != '\0')
		{
			ft_exit("Map is not rectangular !");
			free(line);
		}
		free(line);
	}
	if (!line)
		free(line);
	close(fd);
}

void	ft_add_the_map(t_game *game)
{
	int		y;
	int		fd;
	char	*line;

	fd = open(game->map.map_path, O_RDONLY);
	y = 0;
	game->map.map_graph = malloc(sizeof(char *) * (game->map.width + 1));
	if (!(game->map.map_graph))
		ft_exit("MAP CAN NOT MALLOCED !");
	while (y <= game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		game->map.map_graph[y] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!(game->map.map_graph[y]))
			ft_exit("MAP CAN NOT MALLOCED !");
		game->map.map_graph[y] = line;
		game->map.map_graph[y][ft_strlen(line)] = '\0';
		y++;
	}
	game->map.map_graph[y] = 0;
	close(fd);
}

void	ft_scan_the_map(t_game *game)
{
	int	x;
	int	y;

	game->map.coin_number = 0;
	game->map.exit_number = 0;
	game->map.player_number = 0;
	game->map.unallowed_char_number = 0;
	game->map.player_plus_coin_nbr = 0;
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map_graph[y][x] == 'C')
				game->map.coin_number += 1;
			else if (game->map.map_graph[y][x] == 'E')
			{
				game->map.exit_number += 1;
				game->exit_x = x;
				game->exit_y = y;
			}
			else if (game->map.map_graph[y][x] == 'P')
			{
				game->map.player_number += 1;
				game->player.x = x;
				game->player.y = y;
			}
			else if (game->map.map_graph[y][x] != '1' &&
					game->map.map_graph[y][x] != '0')
				game->map.unallowed_char_number += 1;
		}
	}
}

void	ft_element_number_control(t_game *game)
{
	if (game->map.coin_number < 1)
		ft_exit("MAP must have at least 1 COLLECTIBLES !");
	else if (game->map.exit_number != 1)
		ft_exit("MAP must have 1 EXIT !");
	else if (game->map.player_number != 1)
		ft_exit("MAP must have 1 PLAYER !");
	else if (game ->map.unallowed_char_number != 0)
		ft_exit("The map must contain {0,1,E,P,C} elements !");
}

void	ft_is_valid_map(t_game *game)
{
	ft_rectangular_control(game);
	ft_add_the_map(game);
	ft_scan_the_map(game);
	ft_element_number_control(game);
	ft_wall_control(game);
	ft_is_player_reach(game);
}
