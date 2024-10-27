/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:01:10 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/23 17:35:46 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rows(t_game *game);
static void	check_columns(t_game *game);
static void	var_count(t_game *game);
static void	validate_map(t_game *game);

void	check_map(t_game *game)
{
	check_rows(game);
	check_columns(game);
	var_count(game);
	validate_map(game);
}

static void	check_rows(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map.pixel[0][i])
	{
		if (game->map.pixel[0][i] != WALL)
			error_message("Incorrect map", game);
		i++;
	}
	while (game->map.pixel[game->map.rows - 1][j])
	{
		if (game->map.pixel[game->map.rows - 1][j] != WALL)
			error_message("Incorrect map", game);
		j++;
	}
}

static void	check_columns(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.pixel[i] != NULL)
	{
		if (game->map.pixel[i][0] != WALL)
			error_message("Incorrect map", game);
		i++;
	}
	i = 0;
	j = game->map.columns - 1;
	while (i < game->map.rows)
	{
		if (game->map.pixel[i][j] != WALL)
			error_message("Incorrect map", game);
		i++;
	}
}

static void	var_count(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map.pixel[y] != NULL)
	{
		x = 0;
		while (game->map.pixel[y][x] != '\0')
		{
			if (!ft_strchr("01PCE", game->map.pixel[y][x]))
				error_message("Invalid map: unexpected parameter.", game);
			else if (game->map.pixel[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.pixel[y][x] == COIN)
				game->map.coins++;
			else if (game->map.pixel[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

static void	validate_map(t_game *game)
{
	if (game->map.players > 1)
		error_message("Invalid map: there must be only one player", game);
	if (game->map.players < 1)
		error_message("Invalid map: there must be a player", game);
	if (game->map.coins < 1)
		error_message("Invalid map: there are no coins", game);
	if (game->map.exit > 1)
		error_message("Invalid map: there must be only one exit", game);
	if (game->map.exit < 1)
		error_message("Invalid map: there must be an exit", game);
}
