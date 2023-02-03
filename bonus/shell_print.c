/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:07:01 by cbolat            #+#    #+#             */
/*   Updated: 2023/02/03 10:49:39 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_step_count(t_game *game)
{
	game->player.move_count += 1;
}

void	ft_exit(char *str)
{
	ft_printf("Error: \033[31m%s\n\033[0m", str);
	exit (0);
}

void	ft_warning(char *str)
{
	ft_printf("Error: \033[31m%s\n\033[0m", str);
}

void	ft_exit_suc(char *str)
{
	ft_printf("\033[32m%s\n\033[0m", str);
	exit (0);
}

void	ft_exit_and_free(char *line)
{
	ft_printf("Error: \033[31mMap is not rectangular !\n\033[0m");
	free(line);
	exit (0);
}
