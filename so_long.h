/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:42:26 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/21 23:27:34 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL 1
# define FREE 0
# define COLLECTIABLES 67
# define EXIT 69
# define STARTING POS 80

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include <fcntl.h>

typedef struct s_images
{
	char *collectibles_path;
	char *player_path;
	char *wall_path;
	char *exit_path;
	char *background_path;
	int height;
	int	width;
} t_images;

typedef struct s_player
{
	int	x;
	int	y;
	int	coin_collected;
	int	move;
}	t_player;

typedef struct s_map
{
	char	**map_graph;
	int		height;
	int		width;
	char	*map_path;
} t_map;

typedef struct s_game
{
	struct s_map map;
	struct s_player player;
	struct s_images images;
	int	coin_check;
	int	player_check;
	int	exit_check;
} t_game;

void	ft_exit(char *str);
void	ft_argument_control(char **argv, int argc);
void	ft_image_control(t_game *game);
void	ft_map_control(char **argv);

#endif
