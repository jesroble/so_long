/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:35:02 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/21 15:19:06 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image(t_game *game);

void	free_all_mem(t_game *game)
{
	destroy_image(game);
	free_map(game);
	mlx_close_window(game->mlx);
	free(game->mlx);
	free(game);
}

static void	destroy_image(t_game *game)
{
	mlx_delete_texture(game->wall.texture);
	mlx_delete_texture(game->floor.texture);
	mlx_delete_texture(game->coin.texture);
	mlx_delete_texture(game->open_exit.texture);
	mlx_delete_texture(game->closed_exit.texture);
	mlx_delete_texture(game->player_back.texture);
	mlx_delete_texture(game->player_front.texture);
	mlx_delete_texture(game->player_left.texture);
	mlx_delete_texture(game->player_right.texture);
	mlx_delete_image(game->mlx, game->wall.image);
	mlx_delete_image(game->mlx, game->floor.image);
	mlx_delete_image(game->mlx, game->coin.image);
	mlx_delete_image(game->mlx, game->open_exit.image);
	mlx_delete_image(game->mlx, game->closed_exit.image);
	mlx_delete_image(game->mlx, game->player_back.image);
	mlx_delete_image(game->mlx, game->player_front.image);
	mlx_delete_image(game->mlx, game->player_left.image);
	mlx_delete_image(game->mlx, game->player_right.image);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(game->map.pixel[i++]);
	}
	free(game->map.pixel);
}
