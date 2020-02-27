/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:25:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/27 11:54:07 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Similar to ft_strdup() but returns tab of ints
*/

int		*ft_strdup_int(char const *s1)
{
	int		*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = (int *)ft_memalloc(sizeof(int) * len);
	if (dup)
	{
		while (i < len)
		{
			dup[i] = (int)(s1[i]);
			i += 1;
		}
		return (dup);
	}
	return (NULL);
}
