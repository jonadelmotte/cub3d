/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:30:28 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/17 17:14:55 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_args(int argc, char *argv)
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv);
		if (len <= 4 || ft_strncmp(argv + (len - 4), ".cub", 4) != 0)
		{
			printf("Error\nNot the right map format, it should be .cub\n");
			return (1);
		}
		return (0);
	}
	else
		printf("Not the right amount of arguments\n");
	return (1);
}

int	check_char(t_tools *tools)
{
	int	i;
	int	y;

	i = 0;
	while (tools->map[i])
	{
		y = 0;
		while (tools->map[i][y])
		{
			if (tools->map[i][y] != 'N' && tools->map[i][y] != 'W'
				&& tools->map[i][y] != 'S' && tools->map[i][y] != 'E'
				&& tools->map[i][y] != FLOOR && tools->map[i][y] != WALL
				&& ft_is_space(tools->map[i][y]) != 1)
			{
				printf(PINK "Error\nThere is an unauthorized character\n" RESET);
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

int	check_elements(t_data *data, int x, int y, int start_position)
{
	while (data->tools.map[y])
	{
		x = 0;
		while (data->tools.map[y][x])
		{
			if (data->tools.map[y][x] == 'N' || data->tools.map[y][x] == 'W'
				|| data->tools.map[y][x] == 'E' || data->tools.map[y][x] == 'S')
			{
				start_position++;
				data->player.pos_x = x;
				data->player.pos_y = y;
				data->player.direction = data->tools.map[y][x];
				data->tools.map[y][x] = FLOOR;
			}
			x++;
		}
		y++;
	}
	if (start_position != 1)
	{
		printf(PINK "Error\nNot the correct amount of elements\n" RESET);
		return (1);
	}
	return (0);
}

static int open_textures(t_tools *tools)
{
	int fd;
	
	fd = open(tools->EA, O_RDONLY);
	if (fd < 0)
		return (printf("texture doesn't exist\n"), 1);
	close(fd);
	fd = open(tools->NO, O_RDONLY);
	if (fd < 0)
		return (printf("texture doesn't exist\n"), 1);
	close(fd);
	fd = open(tools->SO, O_RDONLY);
	if (fd < 0)
		return (printf("texture doesn't exist\n"), 1);
	close(fd);
	fd = open(tools->WE, O_RDONLY);
	if (fd < 0)
		return (printf("texture doesn't exist\n"), 1);
	close(fd);
	return (0);
}

int	resolve_parsing(t_data *data, int argc, char *argv)
{
	data->tools = init_null();
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
