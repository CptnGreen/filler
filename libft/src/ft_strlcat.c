/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:01:44 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/02 21:02:31 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlcat: considered to be a safer analogue to strcat & strncat
** 1) always null-terminates the result of copying
** (if  there is enough space in dest)
** 2) unlike strncat takes full size of the buffer (uncluding '\0')
** 3) src and dst must be null-terminated
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		size_src;
	size_t		size_dst;

	size_dst = ft_strlen(dst) + 1;
	size_src = ft_strlen(src) + 1;
	if (size < size_dst)
		return (size_src - 1 + size);
	else
	{
		i = 0;
		while (src[i] && size_dst + i < size)
		{
			dst[size_dst - 1 + i] = src[i];
			i++;
		}
		dst[size_dst - 1 + i] = '\0';
		return (size_src - 1 + size_dst - 1);
	}
}
