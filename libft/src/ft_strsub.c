/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:45:34 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 22:10:44 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: ft_strsub() allocates (with malloc(3)) and returns a "fresh"
** substring from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren't refering to a valid
** substring, the behaviour is undefined. If the allocation fails,
** the function returns NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft_strnew(len);
	if (str)
	{
		ft_strncpy(str, s + start, len + 1);
		str[len] = '\0';
		return (str);
	}
	else
		return (NULL);
}
