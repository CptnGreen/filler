/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 02:25:01 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 20:29:27 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strncat: writes no more than n bytes from s2 to the end of s1
** NB: if src_len >= n it does not need to be terminated
*/

#include "libft.h"

char	*ft_strncat(char *restrict s1, char const *restrict s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j] && j < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
