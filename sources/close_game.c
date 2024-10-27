/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:33:40 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/19 21:55:47 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_victory(t_game *game)
{
	ft_printf(BLUE"\n				Movements: %d\n"RESET, ++game->movements);
	free_all_mem(game);
	ft_printf(GREEN"\n\
	██████████████████████████████████████████████████████████████████\n\
	██                                                              ██\n\
	██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
	██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
	██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
	██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
	██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
	██                                                              ██\n\
	██████████████████████████████████████████████████████████████████\n\n\
	"RESET);
	exit (0);
}

void	ft_close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_printf(BLUE"Movements: %d\n"RESET, game->movements);
	free_all_mem(game);
	ft_printf(GREY"CLOSED\n"RESET);
	exit (0);
}

void	error_message(char *message, t_game *game)
{
	if (game->map_alloc == true)
		free_map(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit (0);
}
