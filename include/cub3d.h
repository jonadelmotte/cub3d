/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:14:28 by jdelmott          #+#    #+#             */
/*   Updated: 2026/10/08 17:17:20 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <curses.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>

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
# define PI 3.14159265358979323846

# define WINDOW_WIDTH 300
# define WINDOW_HEIGHT 300

# define FOV 0.66

# define PINK "\e[38;5;169m"
# define PURPLE_1 "\e[38;5;181m"
# define PURPLE_2 "\e[38;5;161m"
# define RESET "\e[0;39m"

typedef enum e_walls
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}				t_walls;

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

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_raycast
{
	t_pos		rayon;
	t_pos		size_rayon;
	t_pos		map;
	t_pos		size_dist;
	t_pos		step;
	int			side;
	double		player_dist;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	double		wall_pos;
	int			wall_slice;
}				t_raycast;

typedef struct s_player
{
	t_pos		box;
	t_pos		pos;
	t_pos		dir;
	t_pos		view;
	char		direction;
}				t_player;

typedef struct s_colors
{
	int			r_floor;
	int			g_floor;
	int			b_floor;
	int			floor;
	int			r_ceiling;
	int			g_ceiling;
	int			b_ceiling;
	int			ceiling;
}				t_colors;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			img_h;
	int			img_w;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_tools		tools;
	t_player	player;
	t_colors	colors;
	t_img		screen;
	t_img		walls[4];
}				t_data;

/* * * * * * * * * * * * FREE * * * * * * * * * * * * * */
int				free_all(t_data *data);
void			free_tools(t_tools *tools);

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
void			fill_player(char dir, int x, int y, t_player *player);
int				check_sides(char **map);

/* * * * * * * * * * * * MLX * * * * * * * * * * * */
int				init_game(t_data *data);
int				key_hook(int key, t_data *data);
void			init_asset(t_data *data);
int    find_pixel(t_data *data, int x, int y, int wall_side);
void	put_pixel(t_data *data, int x, int y, int color);

/* * * * * * * * * * * RAYCASTING * * * * * * * * * * * */
void			init_raycast(t_data *data);

#endif