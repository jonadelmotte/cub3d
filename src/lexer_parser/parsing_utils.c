/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:47:15 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/22 16:12:15 by sdabbas          ###   ########.fr       */
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
		printf("Error\nNot the right amount of arguments\n");
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
				printf("Error\nThere is an unauthorized character\n");
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
				fill_player(data->tools.map[y][x], y, x, &data->player);
				data->tools.map[y][x] = FLOOR;
			}
			x++;
		}
		y++;
	}
	if (start_position != 1)
	{
		printf("Error\nNot the correct amount of elements\n");
		return (1);
	}
	return (0);
}

int	check_speed(void)
{
	if (P_SPEED > 1)
	{
		printf("Error\n%fWAW this is way to fast\n", P_SPEED);
		return (1);
	}
	if (P_SPEED <= 0)
	{
		printf("Error\n%fWAW what are you even trying to do ?\n", P_SPEED);
		return (1);
	}
	if (C_SPEED <= 0)
	{
		printf("Error\n%fWAW what are you even trying to do ?\n", C_SPEED);
		return (1);
	}
	return (0);
}

int	check_screen(void)
{
	if (WIN_HEIGHT <= 0 || WIN_WIDTH <= 0 || WIN_HEIGHT > 1025
		|| WIN_WIDTH > 1925)
	{
		printf(VERY_IMPORTANT_TO_DEFINE PART_2 PART_3);
		return (1);
	}
	return (0);
}
