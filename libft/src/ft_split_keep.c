/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_keep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:35:37 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/07 15:07:27 by sdabbas          ###   ########.fr       */
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
		while (str[i] != c && str[i])
			i++;
	}
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
		if (str[i] == c && str[i])
		{
			i++;
			j++;
		}
		while (str[i + j] != c && str[i + j])
			j++;
		split[words] = ft_calloc(sizeof(char), j + 1);
		if (!split[words])
			return (free_split(split, words), NULL);
		ft_strlcpy(split[words], (char *)&str[i], j + 1);
		i += j;
		words++;
		if (words == count_words(str, c))
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
