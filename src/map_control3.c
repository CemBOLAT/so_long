/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:50:00 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/27 21:19:19 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_scan_map_2(t_game *game, int y, int x)
{
	if (game->map.map_graph[y][x] == 'P')
	{
		game->map.player_number += 1;
		game->player.x = x;
		game->player.y = y;
	}
	else if (game->map.map_graph[y][x] != '1' &&
		game->map.map_graph[y][x] != '0' &&
		game->map.map_graph[y][x] != 'E' &&
		game->map.map_graph[y][x] != 'P' &&
		game->map.map_graph[y][x] != 'C')
		game->map.unallowed_char_number += 1;
}
