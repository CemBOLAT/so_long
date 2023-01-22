/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cembolat <cembolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:44:12 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/22 22:42:47 by cembolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *str)
{
	write(1, "Error: ", 7);
	ft_printf("\033[31m%s\n\033",str);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		ft_exit("Invalid argument Number!");
	ft_argument_control(argv);
	ft_map_control(argv, &game);
	ft_image_control(&game);
	ft_is_valid_map(&game);
	ft_wall_control(&game);
	//printf("%s",game.images.collectibles_path);
}
