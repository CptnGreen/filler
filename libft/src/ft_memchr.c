/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:38:56 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 19:38:59 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memchr() function scans the initial n bytes of the
** memory area pointed to by s for the first instance of c.
** Both c and the bytes of the memory area pointed to by s
** are interpreted as unsigned char. The memchr() function
** return a pointer to the matching byte or NULL if the
** character does not occur in the given memory area.
*/

void	*ft_memchr(void const *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
