/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:09:09 by sdabbas           #+#    #+#             */
/*   Updated: 2026/08/31 16:10:40 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;
	size_t			m;

	if (!s)
		return ;
	t = (unsigned char *)s;
	m = 0;
	while (m < n)
	{
		t[m] = '\0';
		m++;
	}
}
