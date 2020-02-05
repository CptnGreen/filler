/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:50:46 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 20:28:58 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strcat: writes s2 to the end of s1.
** To avoid unpredictable behaviour:
** 1) s1 and s2 may not overlap
** 2) dest must have enough space for the result
*/

#include "libft.h"

char	*ft_strcat(char *restrict s1, char const *restrict s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
