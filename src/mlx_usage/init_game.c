/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:05:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/22 13:46:33 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	init_image(t_data *data, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->img_w,
			&img->img_h);
	if (!img->mlx_img)
		return (1);
    img->exist = 1;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
    return (0);
}

static int	init_asset(t_data *data)
{
    data->screen.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    data->screen.exist = 1;
    data->screen.addr = mlx_get_data_addr(data->screen.mlx_img, &data->screen.bpp, &data->screen.line_len, &data->screen.endian);
	if (init_image(data, &data->walls[NORTH], data->tools.NO) == 1)
        return (printf("Error\n%s is empty/has no texture\n", data->tools.NO), 1);
    if (init_image(data, &data->walls[SOUTH], data->tools.SO) == 1)
        return (printf("Error\n%s is empty/has no texture\n", data->tools.SO), 1);
    if (init_image(data, &data->walls[EAST], data->tools.EA) == 1)
        return (printf("Error\n%s is empty/has no texture\n", data->tools.EA), 1);
    if (init_image(data, &data->walls[WEST], data->tools.WE) == 1)
        return (printf("Error\n%s is empty/has no texture\n", data->tools.WE), 1);
    return (0);
}

int init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    {
        printf("Error\nMlx init failed\n");
        return (1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
    if (!data->win_ptr)
        return (printf("Error\nCouldn't open the window\n"), 1);
    if (init_asset(data) == 1)
        return (1);
    return (0);
}

void    game(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, (void *)handle_key_hook, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, (void *)handle_key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, (void *)handle_key_release, data);	
	mlx_hook(data->win_ptr, 17, 0, (void *)free_all, data);
	init_raycast(data);	
	mlx_loop(data->mlx_ptr);
    free_all(data);
}

