/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:24:47 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/15 16:59:28 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_empty(t_tools *tools)
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
		return (printf("error: not the right element/format\n"), 1);
	return (0);
}

static int	get_tools(t_tools *tools, char **texture)
{
	int	j;

	j = 0;
	if (texture[0] && texture[0][0] != '\n')
	{
		if (texture && texture[0] && texture[1] && texture[2] && texture[2][0]
			&& texture[2][0] != '\n')
			return (free_split(texture, j), 1);
		else if (!texture[2])
			texture[1] = rm_newline(texture[1]);
		while (texture && texture[j])
			j++;
		if (texture && ((j != 2 && j != 3) || fill_tools(tools, texture) == 1))
			return (free_split(texture, j), 1);
		free_split(texture, j);
	}
	return (0);
}
// ici pb si pas ts les elements

int	lex_line(char **final_tab, t_tools *tools)
{
	int		i;
	int		len;
	char	**texture;

	i = 0;
	len = 0;	
	while (final_tab && final_tab[len])
		len++;
	while (final_tab && final_tab[i] && is_empty(tools))
	{
		if (ft_strncmp(final_tab[i], "\n", ft_strlen(final_tab[i]) != 0))
		{
			texture = ft_split(final_tab[i], ' ');
			if (get_tools(tools, texture) != 0)
				return (free_split(final_tab, len), 1);
		}
		i++;
	}
	tools->map = ft_tab_dup(&final_tab[i]);
	free_split(final_tab, len);
	if (i == 0)
		return (1);
	return (0);
}
