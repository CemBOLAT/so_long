/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:02 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/31 02:27:19 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_key_comb(t_game *game)
{
	mlx_hook(game->mlx.window, KEYPRESS, BUTTONPRESSMASK, ft_key_hook, game);
	mlx_hook(game->mlx.window, DESTROYNOTIFY, BUTTONPRESSMASK, ft_mouse_hook, game);
	//mlx_loop_hook(game->mlx.display_connector, ft_animation, game);
}

int	ft_mouse_hook(int m_code, t_game *game)
{
	(void)m_code;
	ft_exit_free_suc("Exit Success !", game);
	return (0);
}

int	ft_data_walking(int y, int x, t_game *game)
{
	if (game->map.map_graph[game->player.y + y][game->player.x + x] == '1')
		return (0);
	else if (game->map.map_graph[game->player.y + y][game->player.x + x] == 'C')
	{
		game->map.map_graph[game->player.y + y][game->player.x + x] = '0';
		game->player.coin_collected++;
	}
	else if (game->map.map_graph[game->player.y + y][game->player.x + x] == 'V')
		ft_exit_free_suc("Enemy's killed you TRY AGAIN !", game);
	else if (game->map.map_graph[game->player.y + y][game->player.x + x] == 'E')
	{
		if (game->player.coin_collected == game->map.coin_number)
			ft_exit_free_suc("Exit Success !", game);
		else
			ft_warning("You cannot exit without collecting coins!");
		return (0);
	}
	return (1);
}

void	ft_image_move(int keycode, t_game *game, int x)
{
	if (keycode == D || keycode == A)
	{
		if (ft_data_walking(0, x, game) == 0)
			return ;
		mlx_put_image_to_window(game->mlx.display_connector, game->mlx.window,
			game->images.background, game->player.x * IMAGE_SIZE,
			game->player.y * IMAGE_SIZE);
		game->player.x += x;
	}
	if (keycode == W || keycode == S)
	{
		if (ft_data_walking(-x, 0, game) == 0)
			return ;
		mlx_put_image_to_window(game->mlx.display_connector,
			game->mlx.window, game->images.background,
			game->player.x * IMAGE_SIZE, game->player.y * IMAGE_SIZE);
		game->player.y -= x;
	}
	ft_step_count(game);
	ft_display_moves(game);
	mlx_put_image_to_window(game->mlx.display_connector,
		game->mlx.window, game->images.player, game->player.x * IMAGE_SIZE,
		game->player.y * IMAGE_SIZE);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_exit_free_suc("Exit Success !", game);
	else if (keycode == D || keycode == W)
		ft_image_move(keycode, game, 1);
	else if (keycode == A || keycode == S)
		ft_image_move(keycode, game, -1);
	return (0);
}
