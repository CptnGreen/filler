/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:43:07 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/07 12:17:55 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ARRAY_SIZE(Value, Length) ((Value < 0) ? (Length + 2) : (Length + 1))

static int		get_len(int n)
{
	int		len;
	int		n_copy;

	len = 0;
	if (n == 0)
		len = 1;
	else
	{
		n_copy = ((n < 0) ? (n * (-1)) : (n));
		while (n_copy > 0)
		{
			n_copy /= 10;
			len += 1;
		}
	}
	return (len);
}

static void		get_array(char *str, int n, int len)
{
	int		i;
	int		n_copy;

	if (n < 0)
		str[0] = '-';
	n_copy = ((n < 0) ? (n * (-1)) : (n));
	i = ARRAY_SIZE(n, len) - 2;
	while (n_copy > 0)
	{
		str[i] = n_copy % 10 + '0';
		n_copy /= 10;
		i--;
	}
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = get_len(n);
	str = (char *)malloc(sizeof(char) * ARRAY_SIZE(n, len));
	if (str)
	{
		str[ARRAY_SIZE(n, len) - 1] = '\0';
		if (n == 0)
			str[0] = '0';
		else if (n == -2147483648)
			ft_strcpy(str, "-2147483648");
		else
			get_array(str, n, len);
		return (str);
	}
	else
		return (NULL);
}
