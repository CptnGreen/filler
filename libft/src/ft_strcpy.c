/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:51:26 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/14 22:06:24 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strcpy: copies src to dst
** 1) src and dst may not overlap (behaviour is unpredictable)
** 2) dst must be larger or equal then src (same reason)
*/

#include "libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
