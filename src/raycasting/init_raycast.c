/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:46:22 by sdabbas           #+#    #+#             */
/*   Updated: 2026/10/01 17:26:37 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void    init_raycast(t_data *data)
{
    int x;
    double col;
    double rayon_x;
    double rayon_y;

    x = 0;
    while (x < WINDOW_WIDTH)
    {
        col = ((2 * x) / (double)WINDOW_WIDTH) - 1;
        rayon_x = data->player.dir_x + col * data->player.view_x;
        rayon_y = data->player.dir_y + col * data->player.view_y;
        x++;
    }
}

//calucler la distance d'une case
//definir en int position sur la map
//calculer distance avant prochain quadrillage
//algorithme pr calculer quand est le prochain mur (DDA)