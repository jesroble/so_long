/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:34:09 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/21 14:31:58 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	identify_sprite(t_game *game, int x, int y);
static void	player_orientation(t_game *game, int x, int y);
static void	render_sprite(t_game *game, t_image sprite, int x, int y);
static void	print_movements(t_game *game);

void	render_map(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			identify_sprite(game, x, y);
			x++;
		}
		y++;
	}
	print_movements(game);
}

static void	identify_sprite(t_game *game, int x, int y)
{
	char	pixel;

	pixel = game->map.pixel[y][x];
	if (pixel == WALL)
		render_sprite(game, game->wall, x, y);
	if (pixel == FLOOR)
		render_sprite(game, game->floor, x, y);
	if (pixel == COIN)
		render_sprite(game, game->coin, x, y);
	if (pixel == EXIT)
	{
		if (game->map.coins == 0)
			render_sprite(game, game->open_exit, x, y);
		else
			render_sprite(game, game->closed_exit, x, y);
	}
	if (pixel == PLAYER)
		player_orientation(game, x, y);
}

static void	player_orientation(t_game *game, int x, int y)
{
	if (game->player_sprite == FRONT)
		render_sprite(game, game->player_front, x, y);
	else if (game->player_sprite == LEFT)
		render_sprite(game, game->player_left, x, y);
	else if (game->player_sprite == RIGHT)
		render_sprite(game, game->player_right, x, y);
	else if (game->player_sprite == BACK)
		render_sprite(game, game->player_back, x, y);
}

static void	render_sprite(t_game *game, t_image sprite, int x, int y)
{
	mlx_image_to_window(game->mlx, sprite.image, x * 64, y * 64);
}

static void	print_movements(t_game *game)
{
	char	*movements;
	char	*text;

	movements = ft_itoa(game->movements);
	text = ft_strjoin("movements: ", movements);
	mlx_put_string(game->mlx, text, 40, 20);
	free(movements);
	free(text);
}
