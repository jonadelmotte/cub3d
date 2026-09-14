#include <cub3d.h>

static size_t  biggest_line(char **map)
{
    size_t biggest;
    size_t line;
    size_t  i;

    biggest = 0;
    line = 0;
    while (map[line])
    {
        i = 0;
        while (map[line][i])
            i++;
        if (biggest < i)
            biggest = i;
        line++;
    }
    biggest++;
    return (biggest);
}

static void    rm_newline_map(char **map)
{
    size_t line;

    line = 0;
    while (map[line])
    {
        map[line] = rm_newline(map[line]);
        line++;
    }
}

char    **big_map(char **map)
{
    char   **new;
    size_t biggest;
    size_t line;
    size_t i;

    new = final_map(map);
    rm_newline_map(new);
    biggest = biggest_line(new);
    line = 0;
    while (new[line])
    {
        i = 0;
        while (new[line][i])
            i++;
        while (i < biggest)
        {
            new[line] = ft_renew_one(new[line], ' ');
            i++;
        }
        line++;
    }
    return (new);
}

int    is_floor(char **map, int line, int i)
{
    if (line >= 0 && i >= 0 && map[line] && map[line][i] && map[line][i] == FLOOR)
        return (1);
    return (0);
}

int    truc(char **map, int line, int i)
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

int    new_test(char **map)
{
    size_t line;
    size_t i;

    line = 0;
    while (map[line])
    {
        i = 0;
        while (map[line][i])
        {
            if (truc(map, line, i) == 1)
                return (1);
            i++;
        }
        line++;
    }
    return (0);
}
