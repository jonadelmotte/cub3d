/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:49:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/02 16:32:02 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_open(char *argv)
{
	int	fd_file;

	fd_file = open(argv, O_RDONLY);
	if (fd_file == -1)
		return (printf("Error\nFile couldn't be opened\n"), 0);
	return (fd_file);
}

char	**read_file(int fd_file)
{
	char	*tmp;
	char	*join;
	char	**final_tab;

	join = ft_calloc(0, 0);
	tmp = get_next_line(fd_file);
	while (tmp != NULL)
	{
		join = renew(tmp, join);
		free(tmp);
		tmp = get_next_line(fd_file);
	}
	free(tmp);
	final_tab = ft_split(join, '\n');
	free(join);
	return (final_tab);
}
