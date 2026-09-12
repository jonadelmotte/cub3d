#include <libft.h>

char	*ft_join_one(char const *s, char const c)
{
	char	*new;
	size_t	len_s;
	size_t	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	len_s = ft_strlen(s);
	new = malloc(sizeof(char) * (len_s + 2));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	return (new);
}
