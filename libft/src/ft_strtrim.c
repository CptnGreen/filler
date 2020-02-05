/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:41:44 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 22:16:26 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: ft_strtrim() allocates (with malloc(3)) and returns a copy
** of the string given as argument without whitespaces at the beginning or
** at the end of the string. Will be considered as whitespaces the following
** characters: ' ', '\n' and '\t'. If s has no whitespaces at the beginning
** or at the end, the function returns a copy of s. If the allocation fails
** the function returns NULL.
*/

static int	find_prefix_end_index(char const *s, size_t len)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i < (int)len)
		i++;
	return (i);
}

static int	find_suffix_start_index(char const *s, size_t len)
{
	int		i;

	i = (int)len - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int			i;
	size_t		l;
	int			beg;
	int			end;
	char		*str;

	l = ft_strlen(s);
	beg = find_prefix_end_index(s, l);
	end = find_suffix_start_index(s, l);
	if (beg > end)
		return ("\0");
	str = ft_strnew(end - beg + 1);
	if (str)
	{
		i = 0;
		while (i < end - beg + 1)
		{
			str[i] = s[beg + i];
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
