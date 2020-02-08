/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtab_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:43:19 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/09 00:48:17 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**mtab_dup(int **m, unsigned int rows, unsigned int cols)
{
	int					**matrix;
	unsigned int		i;
	unsigned int		j;

	if (!(matrix = (int	**)ft_memalloc((rows + 1) * sizeof(int *))))
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_tabnew(cols);
		j = 0;
		while (j < cols)
		{
			matrix[i][j] = m[i][j];
			j++;
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
