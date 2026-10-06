/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:34 by jdelmott          #+#    #+#             */
/*   Updated: 2026/10/06 14:18:29 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_floor(char **map, int line, int i)
{
	if (line >= 0 && i >= 0 && map[line] && map[line][i]
		&& map[line][i] == FLOOR)
		return (1);
	return (0);
}

static int	is_surrounded(char **map, int line, int i)
{
	if (map[line][i] && ft_is_space(map[line][i]) == 1)
	{
		if (is_floor(map, line - 1, i) == 1)
			return (1);
		if (is_floor(map, line - 1, i - 1) == 1)//angle 1
			return (1);
		if (is_floor(map, line - 1, i + 1) == 1)//angle 2
			return (1);
		if (is_floor(map, line, i - 1) == 1)
			return (1);
		if (is_floor(map, line, i + 1) == 1)
			return (1);
		if (is_floor(map, line + 1, i) == 1)
			return (1);
		if (is_floor(map, line + 1, i - 1) == 1)//angle 3
			return (1);
		if (is_floor(map, line + 1, i + 1) == 1)//angle 4
			return (1);
	}
	return (0);
}

int	verif_map(char **map)
{
	size_t	line;
	size_t	i;

	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (is_surrounded(map, line, i) == 1)
				return (printf("%s\n\n", map[line]), 1);
			i++;
		}
		line++;
	}
	if (check_sides(map) == 1)
		return (printf("Error: the map is not surrounded\n"), 1);
	return (0);
}

static void fill_fov(t_player *player, char dir)
{
	player->direction = dir;
	if (player->direction == 'N')
	{
		player->view.x = FOV;
		player->view.y = 0;
	}
	else if (player->direction == 'S')
	{
		player->view.x = -FOV;
		player->view.y = 0;
	}
	else if (player->direction == 'E')
	{
		player->view.x = 0;
		player->view.y = FOV;
	}
	else if (player->direction == 'W')
	{
		player->view.x = 0;
		player->view.y = -FOV;
	}
}

void	fill_player(char dir, int y, int x, t_player *player)
{
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	player->box.x = x;
	player->box.y = y;
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	fill_fov(player, dir);
}
