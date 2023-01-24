/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:46:52 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/24 12:47:38 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *str)
{
	write(1, "Error: ", 7);
	ft_printf("\033[31m%s\n\033[0m", str);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_exit("Invalid argument Number!");
	ft_argument_control(argv);
	ft_map_control(argv, &game);
	ft_image_control(&game);
	ft_image_control_2(&game);
	ft_is_valid_map(&game);
	ft_wall_control(&game);
	ft_minilibx_create(&game);
	//ft_is_player_reach(&game);
	mlx_loop(game.mlx.display_connector);
	//printf("%s", (char *)game->)
	//ft_shell_print(&game);
	//printf("%s",game.images.collectibles_path);
}
