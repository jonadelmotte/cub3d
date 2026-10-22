/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:40:16 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/22 16:12:47 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	verif_map_pos(t_data *data, double y, double x)
{
	if (y >= 0 && x >= 0 && y <= data->tools.map_size && data->tools.map[(int)y]
		&& x <= ft_strlen(data->tools.map[(int)y])
		&& data->tools.map[(int)y][(int)x] != WALL)
		return (1);
	return (0);
}

void	player_move(t_data *data, double side, int way)
{
	t_pos	move;

	if (way == 0)
	{
		move.x = side * data->player.dir.x * P_SPEED;
		move.y = side * data->player.dir.y * P_SPEED;
	}
	else
	{
		move.x = side * data->player.view.x * P_SPEED;
		move.y = side * data->player.view.y * P_SPEED;
	}
	if (verif_map_pos(data, data->player.pos.y + move.y, data->player.pos.x
			+ move.x) == 1)
	{
		data->player.pos.x += move.x;
		data->player.pos.y += move.y;
		data->player.box.x = (int)data->player.pos.x;
		data->player.box.y = (int)data->player.pos.y;
		init_raycast(data);
	}
}
