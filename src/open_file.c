/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:49:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/15 12:05:56 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_open(char *argv)
{
	int	fd_file;

	fd_file = open(argv, O_RDONLY);
	if (fd_file == -1)
		return (printf(PINK "Error\nFile couldn't be opened\n" RESET), -1);
	return (fd_file);
}

static char	**read_file(int fd_file)
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
	final_tab = ft_split_keep(join, '\n');
	free(join);
	close(fd_file);
	return (final_tab);
}

int	final_lexer(t_data *data, char *argv)
{
	char	**tmp;
	int	fd;
	
	fd = check_open(argv);
	if (fd == - 1)
		return (1);
	tmp = read_file(fd);
	if (tmp == NULL)
		return (close(fd), 1);
	if (lex_line(tmp, &data->tools) == 1)
		return (1);
	close (fd);
	return (0);
}
