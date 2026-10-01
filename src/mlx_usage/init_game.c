/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:05:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/01 12:43:43 by sdabbas          ###   ########.fr       */
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
    init_asset(data);
    return (0);
}

static void	init_image(t_data *data, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->img_w,
			&img->img_h);
	if (!img->mlx_img)
		return ;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
}

void	init_asset(t_data *data)
{
	init_image(data, &data->walls[NORTH], data->tools.NO);
    init_image(data, &data->walls[SOUTH], data->tools.SO);
    init_image(data, &data->walls[EAST], data->tools.EA);
    init_image(data, &data->walls[WEST], data->tools.WE);
}

int key_hook(int key, t_data *data)
{
    if (key == ESC)
        free_all(data);
    if (key == KEY_W)
        printf("move up\n");
    if (key == KEY_S)
        printf("move down\n");
    if (key == KEY_A)
        printf("move left\n");
    if (key == KEY_D)
        printf("move right\n");
    if (key == LEFT)
        printf("look left\n");
    if (key == RIGHT)
        printf("look right\n");
    return (0);
}