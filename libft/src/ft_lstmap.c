/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:49:15 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 19:49:16 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstmap() iterates a list *lst* and applies the function *f* to
** each link to create a "fresh" list (using malloc(3)) resulting from
** the successive applications of *f*. If the allocation fails, the
** function returns NULL. Return value: the new list.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*root;

	if (!(new = f(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	root = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (root);
}
