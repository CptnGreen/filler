/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:54:36 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/06 04:54:41 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Similar to ft_strchr() but for ints
*/

int		*ft_tabint(int const *ptr, size_t size, int c)
{
	int			*tab;
	size_t		i;
	int			fd_output;

	fd_output = open("test1", O_WRONLY | O_APPEND);
	tab = (int *)ptr;
	i = 0;
	while (i < size)
	{
		if (tab[i] == c)
			return (tab + i);
		ft_putnbr_fd(tab[i], fd_output);
		ft_putchar_fd('\n', fd_output);
		i += 1;
	}
	ft_putchar_fd('\n', fd_output);
	return (0);
}
