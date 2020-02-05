/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:03:33 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 04:35:33 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_mstr(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = 0;
		while (matrix[i])
		{
			ft_putendl(matrix[i]);
			i++;
		}
		wipe_mstr(matrix);
	}
}
