/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:46:47 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/24 12:43:36 by cbolat           ###   ########.fr       */
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
	//mini_map[y - 1][game->map.width - 1] = 1;
	ft_map_tour(game, mini_map, game->exit_x, game->exit_y);
	ft_printf("%d %d %d\n",game->map.coin_number, game-> map.player_number, game->map.player_plus_coin_nbr);
	if (game->map.coin_number + game->map.player_number != game->map.player_plus_coin_nbr)
		ft_exit("Player cannot reach exit and coins together");
}
