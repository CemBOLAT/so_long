/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:46:47 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/23 18:06:04 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
					ft_exit("The map must has surrounded by the walls !");
		if (y == game->map.height - 1)
			while (x < game->map.width)
				if (game->map.map_graph[y][x++] != '1')
					ft_exit("The map must has surrounded by the walls !");
		if (game->map.map_graph[y][0] != '1' ||
				game->map.map_graph[y][game->map.width - 1] != '1')
			ft_exit("The map must has surrounded by the walls !");
		y++;
	}
}

//nooot
void	ft_map_tour(t_game *game, int **mini_map, int x, int y)
{
	if (game->map.map_graph[y][x] == 'P' || game->map.map_graph[y][x] == 'C')
		game->map.player_plus_coin_nbr += 1;
}


void	ft_is_player_reach(t_game *game)
{
	int	**mini_map;
	int	x;
	int	y;

	y = 0;
	mini_map = (int **)malloc(sizeof(int *) * game->map.width);
	while (y < game->map.height)
	{
		x = 0;
		mini_map[y] = (int *)malloc(sizeof(int) * game->map.width);
		while (x < game->map.width)
		{
			mini_map[y][x] = 0;
			x++;
		}
		y++;
	}
	mini_map[y][x] = 1;
	ft_map_tour(game, mini_map, game->exit_x, game->exit_y);
}
