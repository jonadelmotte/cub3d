/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:29:08 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/14 17:53:10 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int main(int argc, char *argv[])
{
    t_data data;
 
    if (resolve_parsing(&data, argc, argv[1]) == 1)
        return (free_tools(&data.tools), 1);
    printf(PINK "NO = %s\nSO = %s\nWE = %s\nEA = %s\nF = %s\nC = %s\n" RESET, data.tools.NO, data.tools.SO, data.tools.WE, data.tools.EA, data.tools.F, data.tools.C);
    for (int i = 0; data.tools.map[i]; i++)
        printf(PURPLE_1 "%s" RESET PINK "@\n" RESET, data.tools.map[i]);
    free_tools(&data.tools);
}
