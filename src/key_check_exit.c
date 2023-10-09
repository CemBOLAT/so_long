/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:04:08 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/10 01:05:15 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit2(t_game *game, int keycode)
{
	if (keycode == A
		&& (game->map.map_graph[game->player.y][game->player.x + 1] == 'E'))
	{
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.exit,
			(game->player.x + 1) * IMAGE_SIZE, game->player.y * IMAGE_SIZE);
	}
	else if (keycode == D
		&& (game->map.map_graph[game->player.y][game->player.x - 1] == 'E'))
	{
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.exit,
			(game->player.x - 1) * IMAGE_SIZE, game->player.y * IMAGE_SIZE);
	}
}

void	ft_check_exit(t_game *game, int keycode)
{
	if (keycode == W
		&& (game->map.map_graph[game->player.y + 1][game->player.x] == 'E'))
	{
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.exit,
			game->player.x * IMAGE_SIZE, (game->player.y + 1) * IMAGE_SIZE);
	}
	else if (keycode == S
		&& (game->map.map_graph[game->player.y - 1][game->player.x] == 'E'))
	{
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.exit,
			game->player.x * IMAGE_SIZE, (game->player.y - 1) * IMAGE_SIZE);
	}
	else
		ft_check_exit2(game, keycode);
}
