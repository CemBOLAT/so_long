/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:07:01 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/29 22:03:05 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_step_count(t_game *game)
{
	game->player.move_count += 1;
	ft_printf("\033[32mStep\n\033[0m%d !\n", game->player.move_count);
}

void	ft_warning(char *str)
{
	ft_printf("Error: \033[31m%s\n\033[0m", str);
}

void	ft_exit_free_map_suc(char *str, t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->map.height)
		free(game->map.map_graph[y]);
	free(game->map.map_graph);
	ft_printf("\033[32m%s\n\033[0m", str);
	exit (0);
}

void	ft_exit_and_free(char *line)
{
	ft_printf("Error: \033[31mMap is not rectangular !\n\033[0m");
	free(line);
	exit (0);
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
	mlx_string_put(game->mlx.display_connector,
		game->mlx.window, 50, 20, 000000, "MOVES: ");
	mlx_string_put(game->mlx.display_connector,
		game->mlx.window, 100, 20, 0x000000, str);
	free(str);
	//ft_import_map(game);
}
