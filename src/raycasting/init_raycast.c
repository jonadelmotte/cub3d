/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:46:22 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/06 16:42:37 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static t_pos   define_size_rayon(t_pos rayon)
{
    t_pos   size_rayon;

	size_rayon.x = 1.0 / rayon.x;
	size_rayon.y = 1.0 / rayon.y;
	if (size_rayon.x < 0)
		size_rayon.x *= -1;
	else if (size_rayon.y < 0)
		size_rayon.y *= -1;
    return (size_rayon);    
}

static t_pos   define_size_dist(t_pos pos, t_raycast ray)
{
    t_pos   size_dist;

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

static t_pos   define_step(t_pos rayon)
{
    t_pos step;

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

void   search_wall(t_data *data, t_raycast *ray)
{
    bool wall;

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

void	init_raycast(t_data *data)
{
	int		i;
	double	col;
    t_raycast ray;

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
		i++; 
	}
}

