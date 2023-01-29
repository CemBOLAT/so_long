/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:56:09 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/29 22:03:29 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_wall_control(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		if (y == 0)
			while (x < game->map.width)
				if (game->map.map_graph[y][x++] != '1')
					ft_exit_free_map("The map must has surrounded by the walls !", game);
		if (y == game->map.height - 1)
			while (x < game->map.width)
				if (game->map.map_graph[y][x++] != '1')
					ft_exit_free_map("The map must has surrounded by the walls !", game);
		if (game->map.map_graph[y][0] != '1' ||
				game->map.map_graph[y][game->map.width - 1] != '1')
			ft_exit_free_map("The map must has surrounded by the walls !", game);
		y++;
	}
}

void	ft_map_tour(t_game *game, int **mini_map, int x, int y)
{
	if (game->map.map_graph[y][x] == 'P' || game->map.map_graph[y][x] == 'C')
		game->map.player_p_c_n += 1;
	if (game->map.map_graph[y][x + 1] != '1' && mini_map[y][x + 1] < 1)
	{
		mini_map[y][x + 1] = mini_map[y][x] + 1;
		ft_map_tour(game, mini_map, x + 1, y);
	}
	if (game->map.map_graph[y + 1][x] != '1' && mini_map[y + 1][x] < 1)
	{
		mini_map[y + 1][x] = mini_map[y][x] + 1;
		ft_map_tour(game, mini_map, x, y + 1);
	}
	if (game->map.map_graph[y - 1][x] != '1' && mini_map[y - 1][x] < 1)
	{
		mini_map[y - 1][x] = mini_map[y][x] + 1;
		ft_map_tour(game, mini_map, x, y - 1);
	}
	if (game->map.map_graph[y][x - 1] != '1' && mini_map[y][x - 1] < 1)
	{
		mini_map[y][x - 1] = mini_map[y][x - 1] + 1;
		ft_map_tour(game, mini_map, x - 1, y);
	}
	return ;
}

void	ft_free_map(int **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_is_player_reach(t_game *game)
{
	int	**mini_map;
	int	y;

	y = 0;
	mini_map = (int **)malloc(sizeof(int *) * game->map.width);
	while (y < game->map.height)
	{
		mini_map[y] = ft_calloc(game->map.width, sizeof(int));
		y++;
	}
	ft_map_tour(game, mini_map, game->exit_x, game->exit_y);
	if
	(game->map.coin_number + game->map.player_number != game->map.player_p_c_n)
	{
		ft_free_map(mini_map, game->map.height);
		ft_exit_free_map("Player cannot reach exit and coins together", game);
	}
	ft_free_map(mini_map, game->map.height);
}
