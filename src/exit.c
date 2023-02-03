/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:09:44 by cbolat            #+#    #+#             */
/*   Updated: 2023/02/03 10:13:23 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_destroy_window(game->mlx.display_connector, game->mlx.window);
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
