/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:46:22 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/08 17:26:45 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static t_pos	define_size_rayon(t_pos rayon)
{
	t_pos	size_rayon;

	size_rayon.x = 1.0 / rayon.x;
	size_rayon.y = 1.0 / rayon.y;
	if (size_rayon.x < 0)
		size_rayon.x *= -1;
	if (size_rayon.y < 0)
		size_rayon.y *= -1;
	return (size_rayon);
}

static t_pos	define_size_dist(t_pos pos, t_raycast ray)
{
	t_pos	size_dist;

	if (ray.rayon.x < 0)
		size_dist.x = (pos.x - ray.map.x) * ray.size_rayon.x;
	else if (ray.rayon.x >= 0)
		size_dist.x = (ray.map.x + 1.0 - pos.x) * ray.size_rayon.x;
	if (ray.rayon.y < 0)
		size_dist.y = (pos.y - ray.map.y) * ray.size_rayon.y;
	else if (ray.rayon.y >= 0)
		size_dist.y = (ray.map.y + 1.0 - pos.y) * ray.size_rayon.y;
	return (size_dist);
}

static t_pos	define_step(t_pos rayon)
{
	t_pos	step;

	if (rayon.x > 0)
		step.x = 1;
	else
		step.x = -1;
	if (rayon.y > 0)
		step.y = 1;
	else
		step.y = -1;
	return (step);
}

void	search_wall(t_data *data, t_raycast *ray)
{
	bool	wall;

	wall = false;
	ray->side = 0;
	while (wall == false)
	{
		if (ray->size_dist.x < ray->size_dist.y)
		{
			ray->map.x += ray->step.x;
			ray->size_dist.x += ray->size_rayon.x;
			ray->side = 0;
		}
		else
		{
			ray->map.y += ray->step.y;
			ray->size_dist.y += ray->size_rayon.y;
			ray->side = 1;
		}
		if (data->tools.map[(int)ray->map.y][(int)ray->map.x] == '1')
			wall = true;
	}
	if (ray->side == 0)
		ray->player_dist = ray->size_dist.x - ray->size_rayon.x;
	else
		ray->player_dist = ray->size_dist.y - ray->size_rayon.y;
}

void	search_wall_height(t_raycast *ray)
{
	ray->wall_height = WINDOW_HEIGHT / ray->player_dist;
	ray->wall_start = -ray->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->wall_end >= WINDOW_HEIGHT)
		ray->wall_end = WINDOW_HEIGHT - 1;
}

void	search_wall_slice(t_data *data, t_raycast *ray)
{
    int wall_side;

    wall_side = define_side(*ray);
	if (ray->side == 0)
		ray->wall_pos = data->player.pos.y + ray->player_dist * ray->rayon.y;
	else if (ray->side == 1)
		ray->wall_pos = data->player.pos.x + ray->player_dist * ray->rayon.x;
	ray->wall_pos -= floor(ray->wall_pos);
	ray->wall_slice = (int)(ray->wall_pos * (double)data->walls[wall_side].img_w);
	if ((ray->side == 0 && ray->rayon.x > 0) || (ray->side == 1
			&& ray->rayon.y < 0))
		ray->wall_slice = data->walls[wall_side].img_w - ray->wall_slice - 1;
    if (ray->wall_slice < 0)
        ray->wall_slice = 0;
    if (ray->wall_slice >= data->walls[wall_side].img_w)
        ray->wall_slice = data->walls[wall_side].img_w - 1;
}

t_walls define_side(t_raycast ray)
{
    if (ray.side == 0)
    {
        if (ray.rayon.x > 0)
            return (WEST);
        else
            return (EAST);
    }
    else
    {
        if (ray.rayon.y > 0)
            return (NORTH);
        else
            return (SOUTH);
    }
}

void    wall_print(t_data *data, t_raycast *ray, int window_i)
{
    int wall_side;
    double  wall_y;
    double  wall_pos;
    int     wall_i;
    int     y;

    y = 0;
    wall_side = define_side(*ray);
    wall_y = (double)data->walls[wall_side].img_h / (double)ray->wall_height;
    wall_pos = (ray->wall_start - (WINDOW_HEIGHT / 2) + (ray->wall_height / 2)) * wall_y;
    while (y < ray->wall_start)
    {
        put_pixel(data, window_i, y, data->colors.ceiling);
        y++;
    }
    while (y <= ray->wall_end)
    {
        wall_i = (int)wall_pos;
        if (wall_i >= data->walls[wall_side].img_h)
            wall_i = data->walls[wall_side].img_h - 1;
        if (wall_i < 0)
            wall_i = 0;
        wall_pos += wall_y;
        put_pixel(data, window_i, y, find_pixel(data, ray->wall_slice, wall_i, wall_side));
        y++;
    }
    while (y < WINDOW_HEIGHT)
    {
        put_pixel(data, window_i, y, data->colors.floor);
        y++;
    }
}

void	init_raycast(t_data *data)
{
	int			i;
	double		col;
	t_raycast	ray;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ray.map.x = (int)data->player.pos.x;
		ray.map.y = (int)data->player.pos.y;
		col = ((2 * i) / (double)WINDOW_WIDTH) - 1;
		ray.rayon.x = data->player.dir.x + col * data->player.view.x;
		ray.rayon.y = data->player.dir.y + col * data->player.view.y;
		ray.step = define_step(ray.rayon);
		ray.size_rayon = define_size_rayon(ray.rayon);
		ray.size_dist = define_size_dist(data->player.pos, ray);
		search_wall(data, &ray);
		search_wall_height(&ray);
		search_wall_slice(&data, &ray);
        wall_print(data, &ray, i);
		i++;
	}
}
