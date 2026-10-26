/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:14:28 by jdelmott          #+#    #+#             */
/*   Updated: 2026/10/26 12:24:01 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <curses.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>

# define VERY_IMPORTANT_TO_DEFINE "Error\nFor safety reasons, we as a team\n"
# define PART_2 "have decided that this is to big for a window\nwith pleasure\n"
# define PART_3 "Team et Tam\n"
# define FLOOR '0'
# define WALL '1'
# define ESC 65307
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define WIN_WIDTH 1925
# define WIN_HEIGHT 1025

# define FOV 0.66 // poser la question a thomas
# define P_SPEED 0.08
# define C_SPEED 0.1

typedef enum e_walls
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}				t_walls;

typedef enum e_keys
{
	K_ESC,
	K_KEY_W,
	K_KEY_S,
	K_KEY_A,
	K_KEY_D,
	K_LEFT,
	K_RIGHT,
}				t_keys;

typedef struct s_tools
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	size_t		map_size;
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
	int			exist;
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
	int			keys[7];
}				t_data;

/* * * * * * * * * * * * FREE * * * * * * * * * * * * * */
int				free_all(t_data *data);
void			free_tools(t_tools *tools);

/* * * * * * * * * * * LEXER * * * * * * * * * * * * * */
t_tools			init_null(void);
void			init_keys(t_data *data);
void			init_walls_exist(t_data *data);
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
int				check_speed(void);
int				check_screen(void);

/* * * * * * * * * * * * MLX * * * * * * * * * * * */
int				init_game(t_data *data);
void			game(t_data *data);
int				find_pixel(t_data *data, int x, int y, int wall_side);
void			put_pixel(t_data *data, int x, int y, int color);
void			handle_key_hook(t_data *data);
void			handle_key_press(int key, t_data *data);
void			handle_key_release(int key, t_data *data);
void			player_move(t_data *data, double side, int way);

/* * * * * * * * * * * RAYCASTING * * * * * * * * * * * */
void			init_raycast(t_data *data);
t_pos			define_size_rayon(t_pos rayon);
t_pos			define_size_dist(t_pos pos, t_raycast ray);
t_pos			define_step(t_pos rayon);
int				define_side(t_raycast ray);
void			search_wall(t_data *data, t_raycast *ray);
void			search_wall_height(t_raycast *ray);
void			search_wall_slice(t_data *data, t_raycast *ray);

#endif