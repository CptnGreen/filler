/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_of_dots.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-sch...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:34:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 00:29:36 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_matrix_of_dots(unsigned int rows, unsigned int cols)
{
	char	**matrix;
	int		i;
	int		j;

	if (!(matrix = (char **)malloc((rows + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_strnew(cols);
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
