/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:25:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/07 14:50:25 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Similar to ft_strdup() but returns tab of ints
*/

int		*ft_strdup_int(char const *str)
{
	int		*dup;
	int		len;
	int		i;

	dup = NULL;
	if (str)
	{
		len = ft_strlen(str);
		if (!(dup = (int *)ft_memalloc(sizeof(int) * len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			dup[i] = (int)(str[i]);
			i += 1;
		}
	}
	return (dup);
}
