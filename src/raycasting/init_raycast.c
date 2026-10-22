/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:46:22 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/22 17:20:07 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	put_pixel_and_continue(t_data *data, int window_i, int y, int color)
{
	put_pixel(data, window_i, y, color);
	return (1);
}

static void	wall_print(t_data *data, t_raycast *ray, int window_i)
{
	int		wall_side;
	double	wall_y;
	double	p;
	int		wall_i;
	int		y;

	y = 0;
	wall_side = define_side(*ray);
	wall_y = (double)data->walls[wall_side].img_h / (double)ray->wall_height;
	p = (ray->wall_start - (WIN_HEIGHT / 2) + (ray->wall_height / 2)) * wall_y;
	while (y < ray->wall_start)
		y += put_pixel_and_continue(data, window_i, y, data->colors.ceiling);
	while (y <= ray->wall_end)
	{
		wall_i = (int)p;
		if (wall_i >= data->walls[wall_side].img_h)
			wall_i = data->walls[wall_side].img_h - 1;
		if (wall_i < 0)
			wall_i = 0;
		p += wall_y;
		y += put_pixel_and_continue(data, window_i, y, find_pixel(data,
					ray->wall_slice, wall_i, wall_side));
	}
	while (y < WIN_HEIGHT)
		y += put_pixel_and_continue(data, window_i, y, data->colors.floor);
}

void	init_raycast(t_data *data)
{
	int			i;
	double		col;
	t_raycast	ray;

	i = 0;
	while (i < WIN_WIDTH)
	{
		ray.map.x = (int)data->player.pos.x;
		ray.map.y = (int)data->player.pos.y;
		col = ((2 * i) / (double)WIN_WIDTH) - 1;
		ray.rayon.x = data->player.dir.x + col * data->player.view.x;
		ray.rayon.y = data->player.dir.y + col * data->player.view.y;
		ray.step = define_step(ray.rayon);
		ray.size_rayon = define_size_rayon(ray.rayon);
		ray.size_dist = define_size_dist(data->player.pos, ray);
		search_wall(data, &ray);
		search_wall_height(&ray);
		search_wall_slice(data, &ray);
		wall_print(data, &ray, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->screen.mlx_img,
		0, 0);
}
