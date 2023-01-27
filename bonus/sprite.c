/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:54:00 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/27 16:33:14 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_enemy_right(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map_graph[y][x] == 'V' &&
				game->map.map_graph[y][x + 1] == '0')
			{
					game->map.map_graph[y][x] = '0';
					game->map.map_graph[y][x + 1] = 'V';
					x++;
			}
		}
	}
	ft_import_map(game);
}

void	ft_move_enemy_left(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map_graph[y][x] == 'V' &&
				game->map.map_graph[y][x - 1] == '0')
			{
					game->map.map_graph[y][x] = '0';
					game->map.map_graph[y][x - 1] = 'V';
					x++;
			}
		}
	}
	ft_import_map(game);
}

void	ft_sprite_2(t_game *game, int step)
{
	if (step % 10 == 0)
	{
		game->images.collectibles = mlx_xpm_file_to_image(
				game->mlx.display_connector,
				game->images.collectibles_path, &game->images.width,
				&game->images.width);
		game->images.player = mlx_xpm_file_to_image(
				game->mlx.display_connector,
				game->images.player_path, &game->images.width,
				&game->images.width);
		game->images.enemy = mlx_xpm_file_to_image(
				game->mlx.display_connector,
				game->images.enemy_path, &game->images.width,
				&game->images.width);
		ft_move_enemy_right(game);
	}
}

void	ft_sprite(t_game *game)
{
	int	step;

	step = game->player.move_count;
	if (step % 10 == 5)
	{
		game->images.collectibles = mlx_xpm_file_to_image(
				game->mlx.display_connector,
				game->images.collectibles_path_bonus, &game->images.width,
				&game->images.width);
		game->images.player = mlx_xpm_file_to_image(
				game->mlx.display_connector,
				game->images.player_path_bonus, &game->images.width,
				&game->images.width);
		game->images.enemy = mlx_xpm_file_to_image(
				game->mlx.display_connector,
				game->images.enemy_path_bonus, &game->images.width,
				&game->images.width);
		ft_move_enemy_left(game);
	}
	ft_sprite_2(game, step);
	ft_import_map(game);
}
