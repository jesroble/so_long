/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:18:47 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/23 13:59:23 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_vars(t_game *game)
{
	game->map.columns = ft_strlen(game->map.pixel[0]);
	game->map.coins = 0;
	game->map.players = 0;
	game->map.exit = 0;
	game->movements = 0;
	game->player_sprite = RIGHT;
	game->map.copy = NULL;
}

void	init_mlx(t_game	*game)
{
	game->mlx = mlx_init(game->map.columns * 64, game->map.rows * 64,
			"so_long", true);
	if (game->mlx == NULL)
		error_message("mlx could not init", game);
}

void	check_texture(t_game *game, mlx_texture_t **txt, char *path)
{
	*txt = mlx_load_png(path);
	if (*txt == NULL)
		error_message("textures could not be loaded", game);
}

void	init_textures(t_game	*game)
{
	check_texture(game, &game->wall.texture, \
		"./sprites/wall_resized.png");
	check_texture(game, &game->floor.texture, \
		"./sprites/background_resized.png");
	check_texture(game, &game->coin.texture, \
		"./sprites/item_resized.png");
	check_texture(game, &game->open_exit.texture, \
		"./sprites/door_open_resized.png");
	check_texture(game, &game->closed_exit.texture, \
		"./sprites/door_closed_resized.png");
	check_texture(game, &game->player_front.texture, \
		"./sprites/main_character.png");
	check_texture(game, &game->player_left.texture, \
		"./sprites/main_character.png");
	check_texture(game, &game->player_right.texture, \
		"./sprites/main_character.png");
	check_texture(game, &game->player_back.texture, \
		"./sprites/main_character.png");
}

void	init_images(t_game	*game)
{
	game->wall.image = mlx_texture_to_image(game->mlx, game->wall.texture);
	game->floor.image = mlx_texture_to_image(game->mlx, game->floor.texture);
	game->coin.image = mlx_texture_to_image(game->mlx, game->coin.texture);
	game->open_exit.image = \
	mlx_texture_to_image(game->mlx, game->open_exit.texture);
	game->closed_exit.image = \
	mlx_texture_to_image(game->mlx, game->closed_exit.texture);
	game->player_front.image = \
	mlx_texture_to_image(game->mlx, game->player_front.texture);
	game->player_left.image = \
	mlx_texture_to_image(game->mlx, game->player_left.texture);
	game->player_right.image = \
	mlx_texture_to_image(game->mlx, game->player_right.texture);
	game->player_back.image = \
	mlx_texture_to_image(game->mlx, game->player_back.texture);
}
