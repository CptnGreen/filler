/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:59:48 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/06 04:03:50 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*dup;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s1);
	dup = NULL;
	dup = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (dup)
	{
		dup[len] = '\0';
		while (s1[++i])
			dup[i] = s1[i];
		return (dup);
	}
	return (NULL);
}
