/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:51:46 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/14 17:35:33 by sdabbas          ###   ########.fr       */
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

char	*rm_newline(char *str)
{
	char	**split;
	char	*retu;
	size_t	i;
	
	i = 0;
	split = ft_split(str, '\n');
	if (split == NULL)
		return (free(str), NULL);	
	while (split[i])
		i++;
	if (str)
		free(str);
	retu = ft_strdup(split[0]);
	if (retu == NULL)
		return (free_split(split, i), NULL);
	free_split(split, i);
	return (retu);
}