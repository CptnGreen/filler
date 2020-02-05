/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_matrices_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:08:59 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 00:22:24 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**join_matrices_str(char **m1, char **m2)
{
	char			**m;
	unsigned int	m1_h;
	unsigned int	m2_h;
	int				i;
	int				j;

	if (!m1 || !m2)
		return (NULL);
	m1_h = get_mstr_h(m1);
	m2_h = get_mstr_h(m2);
	if (!(m = (char **)malloc((m1_h + m2_h + 1) * sizeof(char *))))
		return (NULL);
	j = -1;
	i = -1;
	while (++i < m1_h)
		m[i] = ft_strdup(m1[i]);
	wipe_mstr(m1);
	while (++j < m2_h)
		m[i + j] = ft_strdup(m2[j]);
	m[i + j] = NULL;
	wipe_mstr(m2);
	return (m);
}
