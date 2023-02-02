/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:36:04 by cbolat            #+#    #+#             */
/*   Updated: 2023/02/02 22:34:35 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_import_data(t_game *game)
{
	game->mlx.display_connector = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.display_connector,
			game->map.width * IMAGE_SIZE, game->map.height * IMAGE_SIZE,
			"So_LONG!");
	game->images.background = mlx_xpm_file_to_image(game->mlx.display_connector,
			game->images.background_path, &game->images.width,
			&game->images.height);
	game->images.collectibles = mlx_xpm_file_to_image(
			game->mlx.display_connector,
			game->images.collectibles_path, &game->images.width,
			&game->images.height);
	game->images.exit = mlx_xpm_file_to_image(game->mlx.display_connector,
			game->images.exit_path, &game->images.width, &game->images.height);
	game->images.player = mlx_xpm_file_to_image(game->mlx.display_connector,
			game->images.player_path, &game->images.width,
			&game->images.height);
	game->images.wall = mlx_xpm_file_to_image(game->mlx.display_connector,
			game->images.wall_path, &game->images.width, &game->images.height);
	game->images.enemy = mlx_xpm_file_to_image(game->mlx.display_connector,
			game->images.enemy_path, &game->images.width, &game->images.height);
}

void	ft_import_map_2(t_game *game, int y, int x)
{
	if (game->map.map_graph[y][x] == '1')
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.wall,
			x * IMAGE_SIZE, y * IMAGE_SIZE);
	else if (game->map.map_graph[y][x] == 'P')
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.player,
			x * IMAGE_SIZE, y * IMAGE_SIZE);
	else if (game->map.map_graph[y][x] == 'V')
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.enemy,
			x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	ft_import_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map_graph[y][x] == 'E')
				mlx_put_image_to_window(game->mlx.display_connector,
					game->mlx.window, game->images.exit,
					x * IMAGE_SIZE, y * IMAGE_SIZE);
			else if (game->map.map_graph[y][x] == 'C')
				mlx_put_image_to_window(game->mlx.display_connector,
					game->mlx.window, game->images.collectibles,
					x * IMAGE_SIZE, y * IMAGE_SIZE);
			else if (game->map.map_graph[y][x] == '0')
				mlx_put_image_to_window(game->mlx.display_connector,
					game->mlx.window, game->images.background,
					x * IMAGE_SIZE, y * IMAGE_SIZE);
			ft_import_map_2(game, y, x);
		}
	}
}

void	ft_minilibx_create(t_game *game)
{
	ft_import_data(game);
	ft_import_map(game);
	ft_key_comb(game);
}
