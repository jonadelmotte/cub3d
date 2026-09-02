/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:49:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/02 12:22:39 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_tools	init_null(void)
{
	t_tools	tools;

	tools.NO = NULL;
	tools.SO = NULL;
	tools.WE = NULL;
	tools.EA = NULL;
	tools.F = NULL;
	tools.C = NULL;
	tools.map = NULL;
	return (tools);
}

int	check_args(int argc, char *argv)
{
		int len;

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

int open_file(char *argv)
{
    int fd_file;
    
    fd_file = open(argv, O_RDONLY);
    if (fd_file == -1)
        return (printf("Error\nFile couldn't be opened\n"), 0);
    return (fd_file);
}

int read_file(int fd_file)
{
    int     valid;
    int textures;
    int lines;
    char    *tmp;

    lines = 0;
    textures = 0;
    valid = 0;
    tmp = get_next_line(fd_file);
    while (tmp != NULL && valid == 0)
    {
        //i = pars_line(tmp, &texture, &lines); 
        free(tmp);
        tmp = get_next_line(fd_file);
    }
    free(tmp);
    if (textures < 6 || valid != 0)
        return(0);
    return (lines);
}



// NO                               ./path_to_the_north_texture

// F 220,100,0

// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture

// C 225,30,0

// 11111111111
// 10000000001111
// 1000000000000111111111111
// 1011000001110000000000001
// 1001000000000000000000001111111111
// 1111111110110000011100000000000001
// 100000000011000001110111111111111
// 11110111111111011100000010001
// 11110111111111011101010010001
// 11000000110101011100000010001
// 10000000000000001100000010001
// 10000000000000001101010010001
// 11000001110101011111011110N0111
// 11110111 1110101 101111010001
// 11111111 1111111 111111111111