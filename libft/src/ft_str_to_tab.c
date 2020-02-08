#include "libft.h"

/*
** Similar to ft_strdup() but returns tab of ints
*/

int		*ft_strdup_int(char const *s1)
{
	int		*dup;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s1);
	dup = (char *)ft_memalloc(sizeof(int) * len);
	if (dup)
	{
		while (s1[++i])
			dup[i] = (int)(s1[i]);
		return (dup);
	}
	return (NULL);
}
