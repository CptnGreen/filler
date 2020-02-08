/*
** Similar to ft_strchr() but for ints
*/

#include "libft.h"

int		*ft_tabint(int const *ptr, size_t size, int c)
{
	int		*tab;
	size_t	i;

	tab = (int *)ptr;
	i = 0;
	while (tab[i] != c)
	{
		if (i >= size)
			return (NULL);
		i += 1;
	}
	return (tab);
}
