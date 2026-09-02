/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:33:27 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/02 16:35:12 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_splitlen(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	**ft_split_dup(char **str)
{
	int		i;
	char	**cpy;

	i = 0;
	if (!str)
		return (NULL);
	cpy = ft_calloc(sizeof(char *), (ft_splitlen(str) + 1));
	while (str[i])
	{
		cpy[i] = ft_strdup(str[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
