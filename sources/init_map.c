/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:25 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/26 17:07:53 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	empty_line(char *map, t_game *game);

void	check_command_line(int argc, char **argv, t_game *game)
{
	int	input_len;

	if (argc != 2)
		error_message("Usage: ./so_long *.ber", game);
	input_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][input_len - 4], ".ber", 4))
		error_message("Map item must be .ber", game);
	game->map_alloc = false;
}

void	create_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_message("Map could not be oppened", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = addstr(map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	if (ft_strlen(map_temp) == 0 || game->map.rows == 0)
		error_message("Map is empty or only contains blank lines", game);
	empty_line(map_temp, game);
	game->map.pixel = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

static void	empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error_message("The map starts wit an empty line", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		error_message("The map ends with an empty line", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error_message("The map have an empty line in the middle", game);
		}
		i++;
	}
}
