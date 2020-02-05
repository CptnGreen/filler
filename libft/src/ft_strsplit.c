/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:54:02 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 01:27:13 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strsplit() allocates (with malloc(3)) and returnes
** an array of "fresh" strings (all ending with '\0',
** including the array itself) obtained by splitting s using
** the character c as a delimeter. If the allocation fails
** the function returnes NULL.
** Example: ft_split("*hello*fellow***students*", '*')
** returnes the array ["hello", "fellow", "students"].
*/

static size_t		skip_prefix(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

static size_t		ft_strlen_delim(char const *s, char delim)
{
	size_t		i;

	i = 0;
	while (s[i] != delim && s[i] != '\0')
		i++;
	return (i);
}

static void			distribute_words_delim(char **ar, char const *s, char c)
{
	size_t	num;
	size_t	i;
	size_t	j;
	size_t	is_sep;

	i = skip_prefix(s, c);
	is_sep = 0;
	ar[0] = ft_strnew(ft_strlen_delim(s + i, c) + 1);
	num = 0;
	j = 0;
	while (s[i])
	{
		is_sep = (s[i] == c) ? (1) : (is_sep);
		if (s[i] != c)
		{
			num = (is_sep == 1) ? (num + 1) : (num);
			ar[num] = (is_sep == 1) ? \
						(ft_strnew(ft_strlen_delim(s + i, c) + 1)) : (ar[num]);
			j = (is_sep == 1) ? (0) : (j);
			ar[num][j++] = s[i];
			is_sep = 0;
		}
		i++;
	}
}

static size_t		count_words(char const *s, char c)
{
	size_t		i;
	size_t		num;
	size_t		is_sep;

	if (s[0] != '\0')
	{
		i = 0;
		is_sep = (s[0] == c) ? (1) : (0);
		num = (s[0] == c) ? (0) : (1);
		while (s[i])
		{
			if (s[i] == c)
				is_sep = 1;
			else
			{
				num = (is_sep == 1) ? (num + 1) : (num);
				is_sep = 0;
			}
			i++;
		}
		return (num);
	}
	else
		return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**ar;
	size_t		num;

	num = count_words(s, c);
	ar = (char **)malloc(sizeof(char *) * ((num == 0) ? (0) : (num + 1)));
	if (ar)
	{
		if (num == 0)
			return (ar);
		ar[num] = NULL;
		distribute_words_delim(ar, s, c);
		return (ar);
	}
	return (NULL);
}
