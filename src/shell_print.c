/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:07:01 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/23 18:03:22 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_shell_print(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		ft_printf("%s\n", game->map.map_graph[y]);
		y++;
	}
}
