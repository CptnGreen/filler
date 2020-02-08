#include "libft.h"

int		*ft_tabnew(size_t size)
{
	int		*tab;
	size_t	i;

	tab = (char *)ft_memalloc(sizeof(int) * size);
	if (tab)
	{
		i = 0;
		while (i < size)
			tab[i++] = 0;
		return (tab);
	}
	return (NULL);
}
