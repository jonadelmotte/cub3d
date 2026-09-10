/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:34 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/03 14:54:43 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char **final_map(char **map)
{
    int i;
    char    **temp;
    
    i = 0;
    while (map[i][0] == '\n')
        i++;
    temp = ft_tab_dup(&map[i]);
    while (map[i])
        i++;
    free_split(map, i);
    return (temp);
}

int check_empty_line(char **empty)
{
    size_t i;
    size_t y;

    i = 0;
    while (empty[i])
    {
        if (empty[i][0] == '\n')
            return (1);
        y = 0;
        while (empty[i][y] && (ft_is_space(empty[i][y]) || empty[i][y] == '\n'))
            y++;
        if (y == ft_strlen(empty[i]))
            return (1);
        i++;
    }
    return (0);
}

static int is_just_walls(char *line)
{
    size_t y;

    y = 0;
    while (line[y])
    {
        if (ft_is_space(line[y]) == 0 && line[y] != WALL)
            return (1);
        y++;
    }
    return (0);
}

static int is_surrounded(char *line)
{
    size_t y;
    char last;

    y = 0;
    last = '0';
    while (line[y] && ft_is_space(line[y]) == 1)
        y++;
    if (line[y] != '1')
        return(1);
    while (line[y])
    {
        if (ft_is_space(line[y]) == 0)
            last = line[y];
        y++;
    }
    if (last != '1')
        return (1);
    return (0);
}

int check_sides(char **map)
{
    size_t i;

    i = 0;
    while (map[i])
    {
        if (is_surrounded(map[i]) == 1)
            return (1);
        i++;
    }
    if (is_just_walls(map[0]) == 1 || is_just_walls(map[i - 1]) == 1)
        return (1);
    return (0);
}
