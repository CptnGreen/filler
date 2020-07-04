/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mstr_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:43:19 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/07 14:46:09 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mstr_dup(char const **m, unsigned int rows, unsigned int cols)
{
	char				**matrix;
	unsigned int		i;

	matrix = NULL;
	if (rows != 0 && cols != 0)
	{
		if (!(matrix = (char **)ft_memalloc((rows + 1) * sizeof(char *))))
			return (NULL);
		i = 0;
		while (i < rows)
		{
			matrix[i] = ft_strdup(m[i]);
			i++;
		}
		matrix[i] = NULL;
	}
	return (matrix);
}
