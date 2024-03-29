/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:56:29 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/27 15:09:37 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_minilibx_create(&game);
	mlx_loop(game.mlx.display_connector);
}
