/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:34:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/08 17:18:47 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int    find_pixel(t_data *data, int x, int y, int wall_side)
{
    char    *src;
    int     color;

    color = 0;
    if ((x >= 0 && x < data->walls[wall_side].img_w) && (y >= 0
			&& y < data->walls[wall_side].img_h))
	{
		src = (data->walls[wall_side].addr + (y * data->walls[wall_side].line_len + x * (data->walls[wall_side].bpp / 8)));
        color = *(unsigned int *)src;
	}
    return (color);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;
    
	if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0
			&& y < WINDOW_HEIGHT))
	{
		dst = (data->screen.addr + (y * data->screen.line_len + x * (data->screen.bpp / 8)));
        *(unsigned int *)dst = color;
	}
}
