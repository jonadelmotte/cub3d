/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:29:08 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/07 15:51:27 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int main(int argc, char *argv[])
{
    t_data data;
    int fd;
    
    (void)argc;
    data.tools = init_null();
    fd = check_open(argv[1]);
    lex_line(read_file(fd), &data.tools);
    data.tools.map = final_map(data.tools.map);
    check_elements(&data, 0, 0, 0);
    printf("truc = %i\n", check_sides(data.tools.map));
    printf(PINK "NO = %s\nSO = %s\nWE = %s\nEA = %s\nF = %s\nC = %s\n" RESET, data.tools.NO, data.tools.SO, data.tools.WE, data.tools.EA, data.tools.F, data.tools.C);
    for (int i = 0; data.tools.map[i]; i++)
        printf(PURPLE_1 "%s" RESET, data.tools.map[i]);
    free_tools(&data.tools);
}
