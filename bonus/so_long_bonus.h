/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:42:26 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/31 01:42:56 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define IMAGE_SIZE 50

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define KEYPRESS 2
# define DESTROYNOTIFY 17
# define BUTTONPRESSMASK 1L << 2

typedef struct s_images
{
	char	*collectibles_path;
	char	*collectibles_path_bonus;
	char	*player_path;
	char	*player_path_bonus;
	char	*wall_path;
	char	*exit_path;
	char	*background_path;
	char	*enemy_path;
	char	*enemy_path_bonus;
	void	*collectibles;
	void	*enemy;
	void	*player;
	void	*wall;
	void	*exit;
	void	*background;
	int		height;
	int		width;
}	t_images;

typedef struct s_player
{
	int	x;
	int	y;
	int	coin_collected;
	int	move_count;
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
	int		player_p_c_n;
	char	*map_path;
}	t_map;

typedef struct s_mlx
{
	void	*display_connector;
	void	*window;

}	t_mlx;

typedef struct s_game
{
	struct s_map	map;
	struct s_player	player;
	struct s_images	images;
	struct s_mlx	mlx;
	int				exit_x;
	int				exit_y;
	int				loop;
	int				pos_player;
}	t_game;

void	ft_argument_control(char **argv);
void	ft_image_control(t_game *game);
void	ft_image_control_2(t_game *game);
void	ft_map_control(char **argv, t_game *game);
int	ft_animation(t_game *game);
void	ft_is_valid_map(t_game *game);
void	ft_rectangular_control(t_game *game);
void	ft_scan_the_map(t_game *game, int y, int x);
void	ft_add_the_map(t_game *game, int y, int x);
void	ft_element_number_control(t_game *game);

void	ft_wall_control(t_game *game);
void	ft_map_tour(t_game *game, int **mini_map, int x, int y);
void	ft_free_map(int **map, int y);
void	ft_is_player_reach(t_game *game);

void	ft_minilibx_create(t_game *game);
void	ft_import_data(t_game *game);
void	ft_import_map(t_game *game);

void	ft_step_count(t_game *game);
void	ft_exit(char *str);
void	ft_exit_suc(char *str);
void	ft_warning(char *str);
void	ft_exit_and_free(char *line);

int		ft_key_hook(int keycode, t_game *game);
void	ft_key_comb(t_game *game);
int		ft_mouse_hook(int m_code, t_game *game);
void	ft_image_move(int keycode, t_game *game, int x);
//void	ft_scan_map_2(t_game *game, int y, int x);
void	ft_make_data_zero(t_game *game);
void	ft_exit_free_map(char *str, t_game *game);
void	ft_exit_free_map_suc(char *str, t_game *game);
void	ft_display_moves(t_game *map);
void	ft_exit_free_suc(char *str, t_game *game);

#endif
