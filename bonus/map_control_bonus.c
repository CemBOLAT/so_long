/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:56:03 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/27 16:36:23 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		free(line);
		game->map.height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\0')
			break ;
		if (game->map.width != (int)ft_strlen(line) && line[0] != '\0')
			ft_exit_and_free(line);
	}
	if (!line)
		free(line);
	close(fd);
}

void	ft_add_the_map(t_game *game)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	y = -1;
	fd = open(game->map.map_path, O_RDONLY);
	game->map.map_graph = (char **)malloc(sizeof(char *) * game->map.height);
	while (++y < game->map.height)
	{
		x = -1;
		line = get_next_line(fd);
		game->map.map_graph[y] = malloc(sizeof(char *) * game->map.width);
		if (line == NULL)
			break ;
		while (++x < game->map.width)
			game->map.map_graph[y][x] = line[x];
		game->map.map_graph[y][x] = '\0';
		free(line);
	}
}

void	ft_scan_the_map(t_game *game, int x, int y)
{
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map_graph[y][x] == 'C')
				game->map.coin_nbr += 1;
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
					game->map.map_graph[y][x] != '0' &&
					game->map.map_graph[y][x] != 'V')
				game->map.unallowed_char_number += 1;
		}
	}
}

void	ft_element_number_control(t_game *game)
{
	if (game->map.coin_nbr < 1)
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
	int	x;
	int	y;

	x = -1;
	y = -1;
	ft_rectangular_control(game);
	ft_add_the_map(game);
	game->player.coin_collected = 0;
	game->player.move_count = 0;
	game->map.coin_nbr = 0;
	game->map.exit_number = 0;
	game->map.player_number = 0;
	game->map.unallowed_char_number = 0;
	game->map.player_p_c_n = 0;
	ft_scan_the_map(game, x, y);
	ft_element_number_control(game);
	ft_wall_control(game);
	ft_is_player_reach(game);
}
