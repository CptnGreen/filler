/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:48:47 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 19:48:50 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstdel() takes as a parameter the address of a pointer to a link
** and frees the memory of this link and every successor of that link
** using functions del and free(3). Finally the pointer to the link
** that was just freed must be set to NULL (quite similar to the
** function ft_memdel from the mandatory part). Return value: none.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	while (*alst)
	{
		next = ((*alst)->next);
		ft_lstdelone(alst, del);
		*alst = next;
	}
}
