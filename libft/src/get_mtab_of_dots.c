/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mtab_of_dots.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:32:44 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 22:34:54 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**get_mtab_of_dots(unsigned int rows, unsigned int cols)
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
			matrix[i][j] = '.';
			j++;
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
