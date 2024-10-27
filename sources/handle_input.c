/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:37:32 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/21 15:36:45 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
}

void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	prev_y;
	int	prev_x;

	prev_y = game->map.player.y;
	prev_x = game->map.player.x;
	game->player_sprite = player_sprite;
	if (game->map.pixel[new_y][new_x] == EXIT && game->map.coins == 0)
		ft_victory(game);
	else if (game->map.pixel[new_y][new_x] == FLOOR
	|| game->map.pixel[new_y][new_x] == COIN)
	{
		game->map.pixel[prev_y][prev_x] = FLOOR;
		if (game->map.pixel[new_y][new_x] == COIN)
			game->map.coins--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.pixel[new_y][new_x] = PLAYER;
		game->movements++;
		render_map(game);
	}
}
