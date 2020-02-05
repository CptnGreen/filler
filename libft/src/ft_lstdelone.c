/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:48:19 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 19:48:21 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstdelone() takes as a parameter a link's pointer adddress nad frees
** the memory of the link's content using the function del given as a
** parameter, then frees the link's memory using free(3). The memory of
** next must not be freed under any circumstance. Finally, the pointer to
** the link that was just freed must be set to NULL (quite similar to the
** function ft_memdel in the mandatory part). Return value: none.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
