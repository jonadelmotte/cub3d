/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:14:28 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/01 16:27:58 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
// # include "mlx.h"

# define EMPTY_SPACE '0'
# define WALL '1'
# define ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_cub
{
	char	**map;
	int		width;
	int		height;
}			t_cub;

typedef struct s_lexer
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
    char    **map;
}           t_lexer;

//INIT A NULL : LEX
// GNL avec espace (remplir info des qu'on les croise)
// si tt est rempli sinon error
// parsing map

#endif