/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:34:41 by jdelmott          #+#    #+#             */
/*   Updated: 2026/10/22 15:08:37 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	verif_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ',' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

static int	verif_nb_colors(char *str)
{
	int	nb_colors;
	int	i;

	nb_colors = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			nb_colors++;
		i++;
	}
	if (nb_colors != 2)
		return (1);
	return (0);
}

static int	is_negatif(t_colors *colors)
{
	if (colors->b_ceiling < 0 || colors->r_ceiling < 0 || colors->g_ceiling < 0
		|| colors->b_floor < 0 || colors->r_floor < 0 || colors->g_floor < 0)
		return (printf("Error\nthe rgb numbers should be between 0 and 255\n"),
			1);
	return (0);
}

static int	split_colors(t_data *data)
{
	char	**split;

	split = ft_split(data->tools.c, ',');
	data->colors.r_ceiling = ft_atoi(split[0]);
	data->colors.g_ceiling = ft_atoi(split[1]);
	data->colors.b_ceiling = ft_atoi(split[2]);
	free_split(split, 3);
	split = ft_split(data->tools.f, ',');
	data->colors.r_floor = ft_atoi(split[0]);
	data->colors.g_floor = ft_atoi(split[1]);
	data->colors.b_floor = ft_atoi(split[2]);
	free_split(split, 3);
	return (0);
}

int	color_parsing(t_data *data)
{
	int	temp_r;
	int	temp_g;

	if (verif_char(data->tools.c) == 1 || verif_char(data->tools.f) == 1
		|| verif_nb_colors(data->tools.c) == 1
		|| verif_nb_colors(data->tools.f) == 1)
		return (printf("Error\nNot the right format of colors\n"), 1);
	split_colors(data);
	if (is_negatif(&data->colors) == 1)
		return (1);
	temp_r = data->colors.r_floor << 16;
	temp_g = data->colors.g_floor << 8;
	data->colors.floor = temp_r | temp_g | data->colors.b_floor;
	temp_r = data->colors.r_ceiling << 16;
	temp_g = data->colors.g_ceiling << 8;
	data->colors.ceiling = temp_r | temp_g | data->colors.b_ceiling;
	return (0);
}
