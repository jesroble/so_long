/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:39:09 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/26 17:01:53 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "so_long.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"

# define IMAGE_HEIGHT		32
# define IMAGE_WIDTH		32

# define WALL				'1'
# define FLOOR				'0'
# define PLAYER				'P'
# define COIN				'C'
# define EXIT				'E'

# define KEY_A				97
# define KEY_W				119
# define KEY_S				115
# define KEY_D				100

# define KEY_DOWN			65364
# define KEY_UP				65362
# define KEY_LEFT			65361
# define KEY_RIGHT			65363

# define KEY_Q				113
# define KEY_ESC			65307

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define GREEN				"\033[32m"
# define RED				"\033[31m"
# define BLUE				"\033[34m"
# define GREY				"\033[90m"
# define RESET				"\033[0m"

typedef enum e_bool
{
	BOOL_FALSE,
	BOOL_TRUE
}	t_bool;

typedef struct s_position
{
	int			x;
	int			y;
}	t_position;

typedef struct s_image
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;
}	t_image;

typedef struct s_map
{
	char		**pixel;
	char		**copy;
	int			rows;
	int			columns;
	int			players;
	int			coins;
	int			exit;
	int			c_check;
	int			e_check;
	t_position	player;
}	t_map;

typedef struct s_game
{
	int			movements;
	int			player_sprite;
	mlx_t		*mlx;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coin;
	t_image		open_exit;
	t_image		closed_exit;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

//creation
void	check_command_line(int argc, char **argv, t_game *game);
void	create_map(t_game *game, char *argv);
void	create_vars(t_game *game);
void	check_map(t_game *game);
void	check_path(t_game *game);

//init
void	init_mlx(t_game	*game);
void	init_textures(t_game	*game);
void	init_images(t_game	*game);

//render
void	render_map(void *param);
void	ft_handle_input(mlx_key_data_t keydata, void *param);
void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite);

//error and close
void	ft_victory(t_game *game);
void	error_message(char *message, t_game *game);
void	ft_close_game(void *param);
void	free_all_mem(t_game *game);
void	free_map(t_game *game);

//utils
char	*addstr(char *dst, char *src);
#endif