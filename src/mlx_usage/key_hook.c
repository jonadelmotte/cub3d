/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:13:06 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/22 16:39:10 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	view_move(t_data *data, int side)
{
	t_pos	temp;

	temp.x = data->player.dir.x;
	temp.y = data->player.dir.y;
	data->player.dir.x = (temp.x * cos(C_SPEED * side) - temp.y * sin(C_SPEED
				* side));
	data->player.dir.y = (temp.x * sin(C_SPEED * side) + temp.y * cos(C_SPEED
				* side));
	temp.x = data->player.view.x;
	temp.y = data->player.view.y;
	data->player.view.x = (temp.x * cos(C_SPEED * side) - temp.y * sin(C_SPEED
				* side));
	data->player.view.y = (temp.x * sin(C_SPEED * side) + temp.y * cos(C_SPEED
				* side));
	init_raycast(data);
}

void	handle_key_hook(t_data *data)
{
	if (data->keys[K_ESC] == 1)
		free_all(data);
	if (data->keys[K_KEY_W] == 1)
		player_move(data, 1.0, 0);
	if (data->keys[K_KEY_S] == 1)
		player_move(data, -1.0, 0);
	if (data->keys[K_KEY_A] == 1)
		player_move(data, -1.0, 1);
	if (data->keys[K_KEY_D] == 1)
		player_move(data, 1.0, 1);
	if (data->keys[K_LEFT] == 1)
		view_move(data, -1);
	if (data->keys[K_RIGHT] == 1)
		view_move(data, 1);
}

void	handle_key_press(int key, t_data *data)
{
	if (key == ESC)
		free_all(data);
	if (key == KEY_W)
		data->keys[K_KEY_W] = 1;
	if (key == KEY_S)
		data->keys[K_KEY_S] = 1;
	if (key == KEY_A)
		data->keys[K_KEY_A] = 1;
	if (key == KEY_D)
		data->keys[K_KEY_D] = 1;
	if (key == LEFT)
		data->keys[K_LEFT] = 1;
	if (key == RIGHT)
		data->keys[K_RIGHT] = 1;
	return ;
}

void	handle_key_release(int key, t_data *data)
{
	if (key == ESC)
		free_all(data);
	if (key == KEY_W)
		data->keys[K_KEY_W] = 0;
	if (key == KEY_S)
		data->keys[K_KEY_S] = 0;
	if (key == KEY_A)
		data->keys[K_KEY_A] = 0;
	if (key == KEY_D)
		data->keys[K_KEY_D] = 0;
	if (key == LEFT)
		data->keys[K_LEFT] = 0;
	if (key == RIGHT)
		data->keys[K_RIGHT] = 0;
	return ;
}
