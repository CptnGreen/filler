/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:35:37 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/02 21:35:46 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: Lexicographical comparison between s1 and s2. If the 2 strings
** are identical the function returns 1, or 0 otherwise.
*/

int	ft_strequ(char const *s1, char const *s2)
{
	int	res;

	res = (ft_strcmp(s1, s2) == 0) ? (1) : (0);
	return (res);
}
