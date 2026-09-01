/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:05:09 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/01 11:37:26 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif

static char	*renew(char *buffer, char *retu)
{
	char	*temp;

	return (temp = ft_strjoin(retu, buffer), free(retu), temp);
}

static char	*line(char *buffer)
{
	char	*retu;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	retu = ft_calloc(sizeof(char), i + 2);
	if (!retu)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		retu[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		retu[i++] = '\n';
	return (retu[i] = '\0', retu);
}

static char	*next_line(char	*buffer)
{
	char	*retu;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	retu = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
	if (!retu)
		return (free(buffer), NULL);
	i++;
	while (buffer[i])
		retu[j++] = buffer[i++];
	return (retu[j] = '\0', free(buffer), retu);
}

static char	*read_file(char *retu, int fd)
{
	char	*buffer;
	int		nb_read;

	nb_read = 1;
	if (!retu)
		retu = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (free(buffer), free(retu), NULL);
		buffer[nb_read] = 0;
		retu = renew(buffer, retu);
		if (!retu)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), retu);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*retu;

	if ((fd < 0 && BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = read_file(buffer[fd], fd);
	if (!buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	retu = line(buffer[fd]);
	if (!retu)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = next_line(buffer[fd]);
	if (!buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, retu);
	return (retu);
}
