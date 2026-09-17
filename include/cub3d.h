/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:14:28 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/17 17:11:10 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <libft.h>
// # include "mlx.h"

# define FLOOR '0'
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

# define PINK "\e[38;5;169m"
# define PURPLE_1 "\e[38;5;181m"
# define PURPLE_2 "\e[38;5;161m"
# define RESET "\e[0;39m"

typedef struct s_tools
{
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	char		**map;
}				t_tools;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	char		direction;
}				t_player;

typedef struct s_colors
{
	int			r_floor;
	int			g_floor;
	int			b_floor;
	int			r_ceiling;
	int			g_ceiling;
	int			b_ceiling;
}				t_colors;

typedef struct s_data
{
	t_tools		tools;
	t_player	player;
	t_colors	colors;
}				t_data;

/* * * * * * * * * * * * FREE * * * * * * * * * * * * * */
void	free_all(t_data *data);

/* * * * * * * * * * * LEXER * * * * * * * * * * * * * */
t_tools			init_null(void);
int				lex_line(char **final_tab, t_tools *tools);
int				final_lexer(t_data *data, char *argv);
int				final_map(t_tools *tools);
char			*rm_newline(char *str);

/* * * * * * * * * * * * PARSING * * * * * * * * * * * */
int				check_args(int argc, char *argv);
int				check_char(t_tools *tools);
int				check_elements(t_data *data, int x, int y, int start_position);
int				verif_map(char **map);
int				resolve_parsing(t_data *data, int argc, char *argv);
int				color_parsing(t_data *data);

int				check_sides(char **map);

#endif