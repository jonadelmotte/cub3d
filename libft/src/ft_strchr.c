/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:39:28 by jdelmott          #+#    #+#             */
/*   Updated: 2026/09/01 16:06:22 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c2;

	c2 = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *)s + i);
		i++;
	}
	if (c2 == '\0')
		return ((char *)s + i);
	return (NULL);
}
