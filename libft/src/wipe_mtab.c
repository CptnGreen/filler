/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_mtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:13:23 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 22:20:58 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This one is like wipe_mstr() but for int arrays
*/

#include "libft.h"

void	wipe_mtab(int **m, size_t rows, size_t cols)
{
	size_t		i;

	i = 0;
	while (i < rows)
	{
		ft_bzero(m + i, cols);
		ft_memdel((void **)(m + i));
		i++;
	}
	free(m);
	m = NULL;
}
