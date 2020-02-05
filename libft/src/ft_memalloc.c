/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:14:26 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/22 23:24:16 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	ptr = NULL;
	if (size != 0)
	{
		ptr = malloc(sizeof(char) * size);
		if (!ptr)
			return (NULL);
		else
		{
			str = (char *)ptr;
			i = 0;
			while (i < size)
			{
				str[i] = 0;
				i++;
			}
		}
	}
	return (ptr);
}
