/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:29:08 by jdelmott          #+#    #+#             */
/*   Updated: 2026/10/01 12:50:45 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	if (resolve_parsing(&data, argc, argv[1]) == 1)
		return (free_tools(&data.tools), 1);
	if (init_game(&data) == 1)
		return (free_all(&data), 1);
	mlx_hook(data.win_ptr, 2, 1L << 0, (void *)key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, (void *)free_all, &data);
	mlx_loop(data.mlx_ptr);
	// printf(PINK "NO = %s\nSO = %s\nWE = %s\nEA = %s\nF = %s\nC = %s\n\n" RESET,
	// 	data.tools.NO, data.tools.SO, data.tools.WE, data.tools.EA,
	// 	data.tools.F, data.tools.C);
	// for (int i = 0; data.tools.map[i]; i++)
	// 	printf(PURPLE_1 "%s" RESET PINK "@\n" RESET, data.tools.map[i]);
	// printf(PURPLE_2 "\nplayer = %c\npos y = %i\npos x = %i\ndir x = %f\ndir y = %f\n\n" RESET, data.player.direction, data.player.pos_y, data.player.pos_x, data.player.dir_x, data.player.dir_y);
	// printf(PINK "F_R = %i, F_G = %i, F_B = %i\nC_R = %i, C_G = %i, C_B = %i\n\n" RESET, data.colors.r_floor, data.colors.g_floor, data.colors.b_floor, data.colors.r_ceiling, data.colors.g_ceiling, data.colors.b_ceiling);
	free_all(&data);
}
