/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cembolat <cembolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:42:26 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/22 22:43:00 by cembolat         ###   ########.fr       */
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
#include "./get_next_line/get_next_line.h"
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
	int		coin_number;
	int		player_number;
	int		exit_number;
	int		unallowed_char_number;
	int		wall_number;
	int		space_number;
	char	*map_path;
} t_map;

typedef struct s_game
{
	struct s_map map;
	struct s_player player;
	struct s_images images;
} t_game;

void	ft_exit(char *str);
void	ft_argument_control(char **argv);
void	ft_image_control(t_game *game);
void	ft_map_control(char **argv, t_game *game);
void	ft_is_valid_map(t_game *game);
void	ft_rectangular_control(t_game *game);
void	ft_scan_the_map(t_game *game);
void	ft_add_the_map(t_game *game);
void    ft_element_number_control(t_game *game);
void 	ft_wall_control(t_game *game);

#endif
