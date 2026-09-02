/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:29:08 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/02 16:42:29 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int main(int argc, char *argv[])
{
    t_tools tools;
    int fd;
    
    (void)argc;
    fd = check_open(argv[1]);
    lex_line(read_file(fd), &tools);
    printf("NO = %s\nSO = %s\nWE = %s\nEA = %s\nF = %s\nC = %s\n", tools.NO, tools.SO, tools.WE, tools.EA, tools.F, tools.C);
    for (int i = 0; tools.map[i]; i++)
        printf("%s\n", tools.map[i]);
}
