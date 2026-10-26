/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:36:10 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/26 11:55:32 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_pos	define_size_rayon(t_pos rayon)
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

t_pos	define_size_dist(t_pos pos, t_raycast ray)
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

t_pos	define_step(t_pos rayon)
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

int	define_side(t_raycast ray)
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
			return (SOUTH);
		else
			return (NORTH);
	}
}
