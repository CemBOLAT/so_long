/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:50:00 by cbolat            #+#    #+#             */
/*   Updated: 2023/02/02 23:12:11 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_make_data_zero(t_game *game)
{
	game->player.coin_collected = 0;
	game->map.coin_number = 0;
	game->map.exit_number = 0;
	game->map.player_nbr = 0;
	game->map.unallowed_char_number = 0;
	game->map.player_p_c_n = 0;
	game->loop = 0;
	game->pos_player = 0;
	game->player.move_count = 0;
}
