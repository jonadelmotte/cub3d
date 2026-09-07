/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:49:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/07 15:25:17 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_open(char *argv)
{
	int	fd_file;

	fd_file = open(argv, O_RDONLY);
	if (fd_file == -1)
		return (printf(PINK "Error\nFile couldn't be opened\n" RESET), 0);
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
	// printf("JOIN = \n%s\nEND OF JOIN\n", join);
	final_tab = ft_split_keep(join, '\n');
	printf("FINAL_TAB = \n");
	for (int i = 0; final_tab[i]; i++)
		printf(PINK "|||" RESET "%s" PURPLE_1 "|||\n" RESET, final_tab[i]);
	printf("END OF FINAL_TAB\n");
	// exit (127);
	free(join);
	return (final_tab);
}
