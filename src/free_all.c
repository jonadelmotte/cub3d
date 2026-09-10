#include <cub3d.h>

void free_tools(t_tools *tools)
{
    int i;

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
    while (tools->map[i])
        i++;
    if (tools->map)
        free_split(tools->map, i);
}
