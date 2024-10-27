/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:27:46 by jesroble          #+#    #+#             */
/*   Updated: 2024/10/02 12:30:45 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*readbuf(int fd, char *storage);
char	*ft_next_line(char *storage);
char	*clean_storage(char *storage);
char	*ft_free(char **str);
char	*strjoin_gnl(char *s1, char *s2);
size_t	strlen_gnl(char *s);
char	*strchr_gnl(char *s, int c);
char	*substr_gnl(char *s, unsigned int start, size_t len);

#endif
