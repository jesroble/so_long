/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:20:24 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/21 15:09:14 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*addstr(char *dst, char *src)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	newstr = malloc((ft_strlen(dst) + ft_strlen(src) + 1) * sizeof(char));
	if (!newstr)
	{
		free(newstr);
		return (0);
	}
	while (dst[i])
	{
		newstr[i] = dst[i];
		i++;
	}
	while (src[j])
	{
		newstr[i++] = src[j++];
	}
	newstr[i] = '\0';
	if (dst)
		free(dst);
	return (newstr);
}
