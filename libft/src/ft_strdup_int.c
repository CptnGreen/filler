/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:25:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/08 22:25:24 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Similar to ft_strdup() but returns tab of ints
*/

int		*ft_strdup_int(char const *s1)
{
	int		*dup;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s1);
	dup = (int *)ft_memalloc(sizeof(int) * len);
	if (dup)
	{
		while (s1[++i])
			dup[i] = (int)(s1[i]);
		return (dup);
	}
	return (NULL);
}
