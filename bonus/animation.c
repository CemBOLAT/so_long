/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:20:06 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/31 02:26:49 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_animation(t_game *game)
{
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx.display_connector, game->images.player);
	if (game->pos_player == 1)
		game->images.player = mlx_xpm_file_to_image
			(game->mlx.display_connector, "textures/EN1.xpm", &game->images.height, &game->images.height);
	else if (game->pos_player == 2)
		game->images.player = mlx_xpm_file_to_image
			(game->mlx.display_connector, "textures/EN2.xpm", &game->images.height, &game->images.height);
	else if (game->pos_player == 3)
		game->images.player = mlx_xpm_file_to_image
			(game->mlx.display_connector, "textures/EN3.xpm", &game->images.height, &game->images.height);
	else if (game->pos_player == 4)
	{
		game->images.player = mlx_xpm_file_to_image
			(game->mlx.display_connector, "textures/EN4.xpm", &game->images.height, &game->images.height);
		game->pos_player = 0;
	}
	game->pos_player++;
	//ft_import_map(game);
	return (0);
}
