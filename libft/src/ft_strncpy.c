/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 02:59:13 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/18 21:09:00 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncpy: copies len chars form src to dst
** 1) if len < len_src copy is not null-terminated
** 2) if len > len_src remaining (len - len_src) bytes fill with zeroes
*/

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	while (i < MIN_OF_TWO(len, len_src))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}
