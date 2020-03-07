/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:14:26 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/07 14:38:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	if (size != 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * size)))
			return (NULL);
		else
		{
			i = 0;
			while (i < size)
			{
				str[i] = 0;
				i += 1;
			}
		}
	}
	return ((void *)str);
}
