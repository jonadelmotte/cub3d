/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:30:28 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/03 14:54:50 by jdelmott         ###   ########.fr       */
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
				&& tools->map[i][y] != EMPTY_SPACE && tools->map[i][y] != WALL)
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
				data->player.starting_pos = data->tools.map[y][x];
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
