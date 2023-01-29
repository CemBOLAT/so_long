/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:09:44 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/29 22:03:17 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit_free_map(char *str, t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->map.height)
		free(game->map.map_graph[y]);
	free(game->map.map_graph);
	ft_exit(str);
}

void	ft_exit(char *str)
{
	ft_printf("Error: \033[31m%s\n\033[0m", str);
	exit (0);
}
