/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:24:47 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/03 14:15:04 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_tools	init_null(void)
{
	t_tools	tools;

	tools.NO = NULL;
	tools.SO = NULL;
	tools.WE = NULL;
	tools.EA = NULL;
	tools.F = NULL;
	tools.C = NULL;
	tools.map = NULL;
	return (tools);
}

static int is_empty(t_tools *tools)
{
	if (tools->C == NULL || tools->F == NULL || tools->NO == NULL
		|| tools->SO == NULL || tools->EA == NULL || tools->WE == NULL)
		return (1);
	return (0);
}

static int	fill_tools(t_tools *tools, char **texture)
{
	int	len;

	len = ft_strlen(texture[0]);
	if (ft_strncmp(texture[0], "NO", len) == 0 && tools->NO == NULL)
		tools->NO = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "SO", len) == 0 && tools->SO == NULL)
		tools->SO = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "WE", len) == 0 && tools->WE == NULL)
		tools->WE = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "EA", len) == 0 && tools->EA == NULL)
		tools->EA = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "F", len) == 0 && tools->F == NULL)
		tools->F = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "C", len) == 0 && tools->C == NULL)
		tools->C = ft_strdup(texture[1]);
	else
		return (1);
	return (0);
}

int	lex_line(char **final_tab, t_tools *tools)
{
	int		i;
	int		j;
	char	**texture;

	i = 0;
	while (final_tab[i] && is_empty(tools))
	{
		j = 0;
		texture = ft_split(final_tab[i], ' ');
		while (texture[j])
			j++;
		if (j != 2 || fill_tools(tools, texture) == 1)
			return (free_split(texture, j), 1);
		free_split(texture, j);
		i++;
	}
	tools->map = ft_split_dup(&final_tab[i]);
	while (final_tab[i])
		i++;
	free_split(final_tab, i);
	return (0);
}

