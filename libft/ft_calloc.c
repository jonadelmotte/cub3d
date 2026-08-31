/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:06:15 by sdabbas           #+#    #+#             */
/*   Updated: 2026/08/31 16:06:49 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tab;
	long int		n2;
	long int		s2;

	n2 = (long int)nmemb;
	s2 = (long int)size;
	if ((nmemb > SIZE_MAX / size) || (n2 < 0 && s2 < 0))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
