/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:46:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/04 00:11:39 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabnew(size_t size)
{
	int		*tab;
	size_t	i;

	if (!(tab = (int *)ft_memalloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i += 1;
	}
	return (tab);
}
