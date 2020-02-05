/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:41:26 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 01:29:25 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: The memmove() function copies n bytes from memory area src to
** memory area dest. The memory areas may overlap: copying takes place
** as though the bytes in src are first copied into a temporary array that
** does not overlap src or dest, and the bytes are then copied from the
** temporary array to dest. The memmove() function returns a pointer to dest.
*/

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	void	*tmp;

	if (!(tmp = malloc(sizeof(char) * n)))
		return (NULL);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dest, tmp, n);
	return (dest);
}
