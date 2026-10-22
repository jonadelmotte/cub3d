/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:30:28 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/22 16:11:20 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	open_textures(t_tools *tools)
{
	int	fd;

	fd = open(tools->ea, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nEAST texture doesn't exist\n"), 1);
	close(fd);
	fd = open(tools->no, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nNORTH texture doesn't exist\n"), 1);
	close(fd);
	fd = open(tools->so, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nSOUTH texture doesn't exist\n"), 1);
	close(fd);
	fd = open(tools->we, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nWEST texture doesn't exist\n"), 1);
	close(fd);
	return (0);
}

int	resolve_parsing(t_data *data, int argc, char *argv)
{
	init_walls_exist(data);
	init_keys(data);
	data->tools = init_null();
	if (check_screen() == 1 || check_speed() == 1)
		return (1);
	if (check_args(argc, argv) == 1)
		return (1);
	if (final_lexer(data, argv) == 1)
		return (1);
	if (final_map(&data->tools) == 1)
		return (1);
	if (check_char(&data->tools) == 1)
		return (1);
	if (check_elements(data, 0, 0, 0) == 1)
		return (1);
	if (verif_map(data->tools.map) == 1)
		return (1);
	if (color_parsing(data) == 1)
		return (1);
	if (open_textures(&data->tools) == 1)
		return (1);
	return (0);
}
