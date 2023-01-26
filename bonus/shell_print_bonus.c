/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:43 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/26 16:55:01 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_step_count(t_game *game)
{
	game->player.move_count += 1;
	ft_printf("\033[32mStep\n\033[0m %d !\n", game->player.move_count);
}

void	ft_exit(char *str)
{
	ft_printf("Error: \033[31m%s\n\033[0m", str);
	exit (0);
}

void	ft_exit_suc(char *str)
{
	ft_printf("\033[32m%s\n\033[0m", str);
	exit (0);
}

void	ft_display_moves(t_game *game)
{
	char	*str;

	game->player.move_count += 1;
	str = ft_itoa(game->player.move_count);
	mlx_string_put(game->mlx.display_connector, game->mlx.window, 50, 20, 000000, "MOVES: ");
	mlx_string_put(game->mlx.display_connector, game->mlx.window, 70, 20, 0x000000, str);
	free(str);
}
