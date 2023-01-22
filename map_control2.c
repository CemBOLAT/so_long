/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cembolat <cembolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:36:59 by cembolat          #+#    #+#             */
/*   Updated: 2023/01/22 22:44:04 by cembolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_wall_control(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        if (y == 0)
            while (x < game->map.width)
                if (game->map.map_graph[y][x++] != '1')
                    ft_exit("The map must has surrounded by the walls !");
        if (y == game->map.height - 1)
            while (x < game->map.width)
                if (game->map.map_graph[y][x++] != '1')
                    ft_exit("The map must has surrounded by the walls !");
        if (game->map.map_graph[y][0] != '1' ||
                game->map.map_graph[y][game->map.width - 1] != '1')
                    ft_exit("The map must has surrounded by the walls !"); 
        y++;
    }
}