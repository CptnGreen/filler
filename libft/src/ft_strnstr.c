/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:27:05 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/14 21:33:06 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t			h_len;
	size_t			n_len;
	char			*tmp;

	tmp = (char *)haystack;
	if ((n_len = ft_strlen(needle)) == 0)
		return (tmp);
	h_len = ft_strlen(haystack);
	while (tmp + n_len <= haystack + MIN_OF_TWO(h_len, len))
	{
		if (ft_strncmp(tmp, needle, n_len) == 0)
			return (tmp);
		tmp++;
	}
	return (0);
}
