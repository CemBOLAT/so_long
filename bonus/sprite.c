/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:54:00 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/26 16:19:41 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	}
	else if (step % 10 == 0)
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
	}
	ft_import_map(game);
}
