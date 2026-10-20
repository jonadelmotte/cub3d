/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:51:46 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/20 16:05:51 by sdabbas          ###   ########.fr       */
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

void	init_keys(t_data *data)
{
	data->keys[K_ESC] = 0;
	data->keys[K_KEY_W] = 0;
	data->keys[K_KEY_S] = 0;
	data->keys[K_KEY_A] = 0;
	data->keys[K_KEY_D] = 0;
	data->keys[K_LEFT] = 0;
	data->keys[K_RIGHT] = 0;
}

char	*rm_newline(char *str)
{
	char **split;
	char *retu;
	size_t i;

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