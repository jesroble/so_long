/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:23:57 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/24 11:54:22 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(t_game *game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = NULL;
	copy = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
	if (!copy)
		error_message("Map copy could not be created", game);
	while (i < game->map.rows)
	{
		copy[i] = ft_strdup(game->map.pixel[i]);
		i++;
	}
	if (!copy)
	{
		while (i > 0)
			free(copy[--i]);
		free(copy);
		error_message("Map copy could not be created", game);
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_free_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.copy[i] != NULL)
	{
		free(game->map.copy[i]);
		i++;
	}
	free(game->map.copy);
}

static void	move_on_path(int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.columns || y >= game->map.rows
		|| game->map.copy[y][x] == '1' || game->map.copy[y][x] == 'E')
		return ;
	if (game->map.copy[y][x] == 'C')
		game->map.c_check--;
	game->map.copy[y][x] = '1';
	move_on_path(x + 1, y, game);
	move_on_path(x - 1, y, game);
	move_on_path(x, y + 1, game);
	move_on_path(x, y - 1, game);
}

static void	check_exit_path(int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.columns || y >= game->map.rows
		|| game->map.copy[y][x] == '1')
		return ;
	if (game->map.copy[y][x] == 'E')
		game->map.e_check--;
	game->map.copy[y][x] = '1';
	check_exit_path(x + 1, y, game);
	check_exit_path(x - 1, y, game);
	check_exit_path(x, y + 1, game);
	check_exit_path(x, y - 1, game);
}

void	check_path(t_game *game)
{
	game->map.c_check = game->map.coins;
	game->map.copy = ft_copy_map(game);
	move_on_path(game->map.player.x, game->map.player.y, game);
	if (game->map.c_check != 0)
	{
		ft_free_copy(game);
		error_message("Not all coins are reachable", game);
		return ;
	}
	game->map.e_check = 1;
	ft_free_copy(game);
	game->map.copy = ft_copy_map(game);
	check_exit_path(game->map.player.x, game->map.player.y, game);
	if (game->map.e_check != 0)
	{
		ft_free_copy(game);
		error_message("Exit is not reachable after collecting all coins", game);
		return ;
	}
	ft_free_copy(game);
}
