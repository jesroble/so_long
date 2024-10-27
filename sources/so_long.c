/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:30:37 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/24 11:54:33 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_large_rows(t_game *game);
static void	check_large_columns(t_game *game);

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_command_line(argc, argv, game);
	create_map(game, argv[1]);
	create_vars(game);
	check_map(game);
	check_large_columns(game);
	check_large_rows(game);
	check_path(game);
	init_mlx(game);
	init_textures(game);
	init_images(game);
	render_map(game);
	mlx_key_hook(game->mlx, ft_handle_input, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_close_hook(game->mlx, ft_close_game, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_all_mem(game);
}

static void	check_large_columns(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.columns)
	{
		i = 0;
		while (i < game->map.rows && game->map.pixel[i][j])
		{
			if (i >= game->map.rows)
				error_message("Extra large column", game);
			i++;
		}
		j++;
	}
}

static void	check_large_rows(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.pixel[i][j])
		{
			if (j >= game->map.columns)
				error_message("Extra large row", game);
			j++;
		}
		i++;
	}
}
