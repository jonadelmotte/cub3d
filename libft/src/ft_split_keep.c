/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_keep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:35:37 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/15 16:39:01 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c && str[i])
		{
			i++;
			count++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	if (str[i] != c)
		count++;
	return (count);
}

static char	**do_split(char **split, const char *str, char c)
{
	int	words;
	int	i;
	int	j;

	i = 0;
	words = 0;
	while (str[i])
	{
		j = 0;

		while (str[i + j] && str[i + j] != c)
			j++;
		if (str[i + j] && str[i + j] == c)
			j++;
		split[words] = ft_calloc(sizeof(char), j + 1);
		if (!split[words])
			return (free_split(split, words), NULL);
		ft_strlcpy(split[words], (char *)&str[i], j + 1);		
		i += j;
		words++;
		if (words == count_words(str, c) + 1)
			break ;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split_keep(const char *str, char sep)
{
	char	**split;
	int		words;

	words = count_words(str, sep);
	split = ft_calloc(sizeof(char *), words + 1);
	if (split == NULL)
		return (NULL);
	if (!str[0] || words == 0)
		return (split);
	return (do_split(split, str, sep));
}
