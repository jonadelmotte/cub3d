#include <cub3d.h>

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
