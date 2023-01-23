/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:42:26 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/23 18:01:58 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMAGE_SIZE 50

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include "../minilibx/mlx.h"

typedef struct s_images
{
	char *collectibles_path;
	char *player_path;
	char *wall_path;
	char *exit_path;
	char *background_path;
	void *collectibles;
	void *player;
	void *wall;
	void *exit;
	void *background;
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
	int		player_plus_coin_nbr;
	char	*map_path;
} t_map;

typedef struct s_mlx
{
	void	*display_connector;
	void	*window;

} t_mlx;

typedef struct s_game
{
	struct s_map map;
	struct s_player player;
	struct s_images images;
	struct s_mlx mlx;
	int			exit_x;
	int			exit_y;

} t_game;

void	ft_exit(char *str);
void	ft_argument_control(char **argv);
void	ft_image_control(t_game *game);
void	ft_image_control_2(t_game *game);
void	ft_map_control(char **argv, t_game *game);
void	ft_is_valid_map(t_game *game);
void	ft_rectangular_control(t_game *game);
void	ft_scan_the_map(t_game *game);
void	ft_add_the_map(t_game *game);
void	ft_element_number_control(t_game *game);
void	ft_wall_control(t_game *game);
void	ft_shell_print(t_game *game);
void	ft_minilibx_create(t_game *game);
void	ft_import_data(t_game *game);
void	ft_import_images(t_game *game);
void	ft_import_background(t_game *game);
void	ft_import_map(t_game *game);
void	ft_is_player_reach(t_game *game);
void	ft_map_tour(t_game *game, int **mini_map, int x, int y);

#endif
