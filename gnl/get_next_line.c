/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:06:10 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/02 12:33:33 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*next_line;

	if (fd < 0)
		return (NULL);
	if (((storage && !strchr_gnl(storage, '\n')) || !storage))
		storage = readbuf(fd, storage);
	if (!storage)
		return (NULL);
	next_line = ft_next_line(storage);
	if (!next_line)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (next_line);
}

char	*readbuf(int fd, char *storage)
{
	int		i;
	char	*buf;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&storage));
	buf[0] = '\0';
	while (i > 0 && !strchr_gnl(buf, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i > 0)
		{
			buf[i] = '\0';
			storage = strjoin_gnl(storage, buf);
		}
	}
	free(buf);
	if (i == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*ft_next_line(char *storage)
{
	char		*line;
	char		*str;
	int			len;

	str = strchr_gnl(storage, '\n');
	len = (str - storage) + 1;
	line = substr_gnl(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*str;
	int		len;

	str = strchr_gnl(storage, '\n');
	if (!str)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (str - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = substr_gnl(storage, len, strlen_gnl(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (*str);
}
