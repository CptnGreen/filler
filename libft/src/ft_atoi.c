/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:25:46 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 22:17:49 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*trim_prefix(char const *str, short *sign)
{
	int		j;

	j = 0;
	while (str[j] == '\t' || str[j] == '\n' || str[j] == ' ' || \
			str[j] == '\r' || str[j] == '\v' || str[j] == '\f')
		(j)++;
	if (str[j] == '-')
	{
		*sign = -1;
		(j)++;
	}
	else if (str[j] == '+')
		(j)++;
	return ((char *)(str + j));
}

int					ft_atoi(char const *str)
{
	size_t			i;
	short			sign;
	size_t			res;
	char			*s;

	sign = 1;
	s = trim_prefix(str, &sign);
	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i++] - '0');
		if (res > 2147483647)
			return ((sign == -1) ? (0) : (-1));
	}
	return (res * sign);
}
