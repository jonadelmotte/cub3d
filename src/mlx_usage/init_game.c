/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:05:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/30 16:39:27 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    {
        printf("Error\nMlx init failed\n");
        free_all(data);
        return (1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
    if (!data->win_ptr)
        return (printf("Error\nCouldn't open the window\n"), 1);
    return (0);
}

int key_hook(int key, t_data *data)
{
    if (key == ESC)
        free_all(data);
    return (0);
}