/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:15:42 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/13 22:52:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t			h_len;
	size_t			n_len;
	char			*tmp;

	tmp = (char *)haystack;
	if ((n_len = ft_strlen(needle)) == 0)
		return (tmp);
	h_len = ft_strlen(haystack);
	while (tmp + n_len <= haystack + h_len)
	{
		if (ft_strncmp(tmp, needle, n_len) == 0)
			return (tmp);
		tmp++;
	}
	return (0);
}
