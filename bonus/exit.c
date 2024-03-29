/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:09:44 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/10 00:47:48 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

void	ft_exit_free_suc(char *str, t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->map.height)
		free(game->map.map_graph[y]);
	free(game->map.map_graph);
	free(game->map.map_path);
	mlx_destroy_image(game->mlx.display_connector, game->images.background);
	mlx_destroy_image(game->mlx.display_connector, game->images.collectibles);
	mlx_destroy_image(game->mlx.display_connector, game->images.exit);
	mlx_destroy_image(game->mlx.display_connector, game->images.player);
	mlx_destroy_image(game->mlx.display_connector, game->images.wall);
	mlx_destroy_image(game->mlx.display_connector, game->images.enemy);
	mlx_destroy_window((game)->mlx.display_connector, (game)->mlx.window);
	ft_exit_suc(str);
}

void	ft_f_exit(char *str, t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->map.height)
		free(game->map.map_graph[y]);
	free(game->map.map_graph);
	free(game->map.map_path);
	ft_exit(str);
}

void	ft_display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.move_count);
	mlx_put_image_to_window(game->mlx.display_connector,
		game->mlx.window, game->images.wall, 2 * IMAGE_SIZE,
		0 * IMAGE_SIZE);
	mlx_put_image_to_window(game->mlx.display_connector,
		game->mlx.window, game->images.wall, 1 * IMAGE_SIZE,
		0 * IMAGE_SIZE);
	mlx_put_image_to_window(game->mlx.display_connector,
		game->mlx.window, game->images.wall, 0 * IMAGE_SIZE,
		0 * IMAGE_SIZE);
	mlx_string_put(game->mlx.display_connector,
		game->mlx.window, 20, 20, 000000, "MOVES: ");
	mlx_string_put(game->mlx.display_connector,
		game->mlx.window, 70, 20, 0x000000, str);
	free(str);
}
