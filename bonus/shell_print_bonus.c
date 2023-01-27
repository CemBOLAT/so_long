/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:43 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/27 16:39:54 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

	str = ft_itoa(game->player.move_count);
	mlx_string_put(game->mlx.display_connector,
		game->mlx.window, 50, 20, 000000, "MOVES: ");
	mlx_string_put(game->mlx.display_connector,
		game->mlx.window, 100, 20, 0x000000, str);
	free(str);
}

void	ft_exit_and_free(char *line)
{
	ft_printf("Error: \033[31mMap is not rectangular !\n\033[0m");
	free(line);
	exit (0);
}

void	ft_warning(char *str)
{
	ft_printf("Error: \033[31m%s\n\033[0m", str);
}
