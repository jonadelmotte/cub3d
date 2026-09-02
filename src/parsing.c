/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:30:28 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/02 16:30:37 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_args(int argc, char *argv)
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv);
		if (len <= 4 || ft_strncmp(argv + (len - 4), ".cub", 4) != 0)
		{
			printf("Error\nNot the right map format, it should be .cub\n");
			return (1);
		}
		return (0);
	}
	else
		printf("Not the right amount of arguments\n");
	return (1);
}