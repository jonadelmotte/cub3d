/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:28:34 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/22 14:28:40 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_tools(t_tools *tools)
{
	int	i;

	i = 0;
	if (tools->no)
		free(tools->no);
	if (tools->so)
		free(tools->so);
	if (tools->we)
		free(tools->we);
	if (tools->ea)
		free(tools->ea);
	if (tools->f)
		free(tools->f);
	if (tools->c)
		free(tools->c);
	if (tools->map)
	{
		while (tools->map[i])
			i++;
		free_split(tools->map, i);
	}
}

int	free_all(t_data *data)
{
	free_tools(&data->tools);
	if (data->mlx_ptr)
	{
		if (data->screen.exist == 1)
			mlx_destroy_image(data->mlx_ptr, data->screen.mlx_img);
		if (data->walls[NORTH].exist == 1)
			mlx_destroy_image(data->mlx_ptr, data->walls[NORTH].mlx_img);
		if (data->walls[SOUTH].exist == 1)
			mlx_destroy_image(data->mlx_ptr, data->walls[SOUTH].mlx_img);
		if (data->walls[EAST].exist == 1)
			mlx_destroy_image(data->mlx_ptr, data->walls[EAST].mlx_img);
		if (data->walls[WEST].exist == 1)
			mlx_destroy_image(data->mlx_ptr, data->walls[WEST].mlx_img);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
	return (0);
}
