/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:07:01 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/26 15:22:39 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

