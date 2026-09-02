/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:56:16 by sdabbas           #+#    #+#             */
/*   Updated: 2026/09/02 16:45:00 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_is_space(char c);
char	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_strdup(const char *s);
char	*renew(char *buffer, char *retu);
char	**ft_split(const char *str, char sep);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
int     free_split(char **split, int count);
char	**ft_split_dup(char **str);

#endif