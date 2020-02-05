/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:48:56 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 19:48:58 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lastadd() adds the element new at the beginning of the list.
** Return value: none.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*lst_root;

	lst_root = *alst;
	*alst = new;
	new->next = lst_root;
}
