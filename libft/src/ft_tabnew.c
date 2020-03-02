/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:46:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/02 12:47:13 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabnew(size_t size)
{
	int		*tab;
	size_t	i;

	tab = (int *)ft_memalloc(sizeof(int) * size);
	if (tab)
	{
		i = 0;
		while (i < size)
			tab[i++] = 0;
		return (tab);
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
