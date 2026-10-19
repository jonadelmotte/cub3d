/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:13:06 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/19 16:17:27 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void player_move(t_data *data, double y, double x)
{
    if (data->tools.map[(int)(data->player.pos.y + y)][(int)(data->player.pos.x + x)] != WALL)
    {
        data->player.pos.x += x;
        data->player.pos.y += y;
        data->player.box.x = (int)data->player.pos.x;
        data->player.box.y = (int)data->player.pos.y;
        init_raycast(data);
    }
}

static void view_move(t_data *data, int side)
{
    t_pos   temp;

    temp.x = data->player.dir.x;
    temp.y = data->player.dir.y;
    data->player.dir.x = (temp.x * cos(SPEED) - temp.y * sin(SPEED)) * side;
    data->player.dir.y = (temp.x * sin(SPEED) + temp.y * cos(SPEED)) * side;
    init_raycast(data);
}

int key_hook(int key, t_data *data)
{
    if (key == ESC)
        free_all(data);
    if (key == KEY_W)
        player_move(data, 1.0 * SPEED, 0.0 * SPEED);
    if (key == KEY_S)
        player_move(data, -1.0 * SPEED, 0.0 * SPEED);
    if (key == KEY_A)
        player_move(data, 0.0 * SPEED, 1.0 * SPEED);
    if (key == KEY_D)
        player_move(data, 0.0 * SPEED, -1.0 * SPEED);
    if (key == LEFT)
        view_move(data, 1);
    if (key == RIGHT)
        view_move(data, -1);
    return (0);
}
