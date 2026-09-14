/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:34 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/14 17:50:24 by sdabbas          ###   ########.fr       */
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
		if (is_floor(map, line - 1, i - 1) == 1)
			return (1);
		if (is_floor(map, line - 1, i + 1) == 1)
			return (1);
		if (is_floor(map, line, i - 1) == 1)
			return (1);
		if (is_floor(map, line, i + 1) == 1)
			return (1);
		if (is_floor(map, line + 1, i) == 1)
			return (1);
		if (is_floor(map, line + 1, i - 1) == 1)
			return (1);
		if (is_floor(map, line + 1, i + 1) == 1)
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
	return (0);
}
