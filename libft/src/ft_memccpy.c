/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:42:43 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 20:27:28 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: The memccpy() function copies no more than n bytes from memory
** area src to memory area dest, stopping when the character c is found
** (and copied). If the memory areas overlap, the results are undefined.
** The memccpy() function returns a pointer to the next character in dest
** after c or NULL if c was not found in the first n characters of src.
*/

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*s;
	unsigned char		*d;
	unsigned char		sym;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	sym = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == sym)
			break ;
		i++;
	}
	return ((s[i] == sym) ? (d + i + 1) : (NULL));
}
