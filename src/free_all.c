#include <cub3d.h>

void		free_tools(t_tools *tools)
{
	int	i;

	i = 0;
	if (tools->NO)
		free(tools->NO);
	if (tools->SO)
		free(tools->SO);
	if (tools->WE)
		free(tools->WE);
	if (tools->EA)
		free(tools->EA);
	if (tools->F)
		free(tools->F);
	if (tools->C)
		free(tools->C);
	if (tools->map)
	{
		while (tools->map[i])
			i++;
		free_split(tools->map, i);
	}
}

int	free_all(t_data *data)
{
	free_tools(&data->tools);
	if (data->mlx_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->walls[NORTH].mlx_img);
		mlx_destroy_image(data->mlx_ptr, data->walls[SOUTH].mlx_img);
		mlx_destroy_image(data->mlx_ptr, data->walls[EAST].mlx_img);
		mlx_destroy_image(data->mlx_ptr, data->walls[WEST].mlx_img);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
	return (0);
}
