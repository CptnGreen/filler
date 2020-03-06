/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:53:48 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/06 04:53:54 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabdup(int const *tab, size_t size)
{
	int			*dup;
	size_t		i;

	i = 0;
	dup = (int *)ft_memalloc(sizeof(int) * size);
	if (dup)
	{
		while (tab[i])
		{
			dup[i] = tab[i];
			i += 1;
		}
		return (dup);
	}
	return (NULL);
}
