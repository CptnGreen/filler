/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:31:42 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/07 23:42:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mstr_to_str(char **m_str)
{
	int		i;
	int		h;
	int		w;
	char	*str;

	if (m_str)
	{
		i = 0;
		h = get_mstr_h(m_str);
		w = get_mstr_w(m_str);
		str = ft_strnew(h * w);
		while (m_str[i])
		{
			str = ft_strncat(str, m_str[i], w);
			i += 1;
		}
		return (str);
	}
	return (NULL);
}
