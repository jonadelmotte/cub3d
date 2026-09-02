/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:04:22 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/02 15:04:31 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	free_split(char **split, int count)
{
	while (count--)
		free(split[count]);
	free(split);
	exit(1);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
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
		while (str[i] == c && str[i])
			i++;
		while (str[i + j] != c && str[i + j])
			j++;
		split[words] = ft_calloc(sizeof(char), j + 1);
		if (!split[words])
			free_split(split, words);
		ft_strlcpy(split[words], (char *)&str[i], j + 1);
		i += j;
		words++;
		if (words == count_words(str, c))
			break ;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split(const char *str, char sep)
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
