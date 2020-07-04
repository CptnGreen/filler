/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_mtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:13:23 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/10 23:14:10 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This one is like wipe_mstr() but for int arrays
*/

void	wipe_mtab(int **m, size_t rows, size_t cols)
{
	size_t		i;

	i = 0;
	if (m)
	{
		while (m[i] && i < rows)
		{
			ft_bzero(m[i], cols);
			ft_memdel((void **)(m + i));
			i++;
		}
		free(m);
		m = NULL;
	}
}
