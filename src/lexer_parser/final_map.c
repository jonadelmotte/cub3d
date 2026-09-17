#include <cub3d.h>

static int	rm_newline_map(t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->map[i])
	{
		if (ft_strncmp(tools->map[i], "\n", ft_strlen(tools->map[i]) == 0))
			return (printf("error: empty line in map\n"), 1);
		tools->map[i] = rm_newline(tools->map[i]);
		if (tools->map[i] == NULL)
		{
			free_split(tools->map, i);
			tools->map = NULL;
			return (printf("error: malloc\n"), 1);
		}
		i++;
	}
	return (0);
}

static int	verif_newline_map(t_tools *tools)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	while (tools->map[i] && tools->map[i][0] == '\n')
		i++;
	if (!tools->map[i])	
		return (printf("error: map is missing\nso sad\n"), 1);
	while (tools->map[i + j])
		j++;
	temp = ft_tab_dup(&tools->map[i]);
	if (temp == NULL)
		return (printf("error: malloc\n"), 1);
	free_split(tools->map, i + j);
	tools->map = ft_tab_dup(temp);
	if (tools->map == NULL)
		return (free_split(temp, j), printf("error: malloc\n"), 1);
	free_split(temp, j);
	if (rm_newline_map(tools) == 1)
		return (1);
	return (0);
}

static size_t	biggest_line(char **map)
{
	size_t	biggest;
	size_t	line;
	size_t	i;

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

int	final_map(t_tools *tools)
{
	size_t	biggest;
	size_t	line;
	size_t	i;

	if (verif_newline_map(tools) == 1)
		return (1);
	biggest = biggest_line(tools->map);
	line = 0;
	while (tools->map[line])
	{
		i = 0;
		while (tools->map[line][i])
			i++;
		while (i < biggest)
		{
			tools->map[line] = ft_renew_one(tools->map[line], ' ');
			if (tools->map[line] == NULL)
				return (1);
			i++;
		}
		line++;
	}
	return (0);
}
