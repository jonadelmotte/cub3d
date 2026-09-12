#include <libft.h>

char	*ft_renew_one(char *start, char end)
{
	char	*temp;

	return (temp = ft_join_one(start, end), free(start), temp);
}
