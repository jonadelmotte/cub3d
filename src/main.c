/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:29:08 by jdelmott          #+#    #+#             */
/*   Updated: 2026/10/22 13:46:18 by sdabbas          ###   ########.fr       */
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
	game(&data);
	return (0);
}
