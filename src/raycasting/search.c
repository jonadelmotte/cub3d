/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:40:58 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/26 14:06:20 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
		if (data->tools.map[(int)ray->map.y][(int)ray->map.x] == WALL)
			wall = true;
	}
	if (ray->side == 0)
		ray->player_dist = ray->size_dist.x - ray->size_rayon.x;
	else
		ray->player_dist = ray->size_dist.y - ray->size_rayon.y;
}

void	search_wall_height(t_raycast *ray)
{
	if (ray->player_dist <= 0.0001)
		ray->player_dist = 0.0001;
	ray->wall_height = WIN_HEIGHT / ray->player_dist;
	ray->wall_start = -ray->wall_height / 2 + WIN_HEIGHT / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wall_height / 2 + WIN_HEIGHT / 2;
	if (ray->wall_end >= WIN_HEIGHT)
		ray->wall_end = WIN_HEIGHT - 1;
}

void	search_wall_slice(t_data *data, t_raycast *ray)
{
	int	wall_side;

	wall_side = define_side(*ray);
	if (ray->side == 0)
		ray->wall_pos = data->player.pos.y + ray->player_dist * ray->rayon.y;
	else if (ray->side == 1)
		ray->wall_pos = data->player.pos.x + ray->player_dist * ray->rayon.x;
	ray->wall_pos -= floor(ray->wall_pos);
	ray->wall_slice = (int)(ray->wall_pos
			* (double)data->walls[wall_side].img_w);
	if ((ray->side == 0 && ray->rayon.x > 0) || (ray->side == 1
			&& ray->rayon.y < 0))
		ray->wall_slice = data->walls[wall_side].img_w - ray->wall_slice - 1;
	if (ray->wall_slice < 0)
		ray->wall_slice = 0;
	if (ray->wall_slice >= data->walls[wall_side].img_w)
		ray->wall_slice = data->walls[wall_side].img_w - 1;
}
