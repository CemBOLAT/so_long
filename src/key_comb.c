/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:02 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/25 15:56:58 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_comb(t_game *game)
{
	mlx_hook(game->mlx.window, 2, 1L << 2, ft_key_hook, game);
	//mlx_hook(game->mlx.window, 17, 1L << 2, ft_mouse_hook, game);
}

static int	real_walking(int y, int x, t_game *game)
{
	if (game->map.map_graph[game->player.y + y][game->player.x + x] == '1')
		return (0);
	else if (game->map.map_graph[game->player.y + y][game->player.x + x] == 'C')
	{
		game->map.map_graph[game->player.y + y][game->player.x + x] = '0';
		game->player.coin_collected++;
	}
	else if (game->map.map_graph[game->player.y + y][game->player.x + x] == 'E')
	{
		ft_exit("ASDAS");
		return (0);
	}
	return (1);
}

static int	walking(int keycode, t_game *game, int x)
{
	if (keycode == 2 || keycode == 0)
	{
		if (real_walking(0, x, game) == 0)
			return (0);
		mlx_put_image_to_window(game->mlx.display_connector, game->mlx.window, game->images.background,
			game->player.x * IMAGE_SIZE, game->player.y * IMAGE_SIZE);
		game->player.x += x;
	}
	if (keycode == 13 || keycode == 1)
	{
		if (real_walking(-x, 0, game) == 0)
			return (0);
		mlx_put_image_to_window(game->mlx.display_connector, game->mlx.window, game->images.background,
			game->player.x * IMAGE_SIZE, game->player.y * IMAGE_SIZE);
		game->player.y -= x;
	}
	ft_step_count(game);
	mlx_put_image_to_window(game->mlx.display_connector, game->mlx.window, game->images.background,
		game->player.x * IMAGE_SIZE, game->player.y * IMAGE_SIZE);
	mlx_put_image_to_window(game->mlx.display_connector, game->mlx.window, game->images.player,
		game->player.x * IMAGE_SIZE, game->player.y * IMAGE_SIZE);
	return (0);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit("Exit Success");
	else if (keycode == 2 || keycode == 13)
		walking(keycode, game, 1);
	else if (keycode == 0 || keycode == 1)
		walking(keycode, game, -1);
	return (0);
}
