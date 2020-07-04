/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:48:08 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 22:57:48 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstnew() allocates (with malloc(3)) and returns a "fresh" link.
** The variables content and content_size of the new link are
** initialized by copy of the parameters of the function. If the
** parameter content is nul, the variable content is initialized
** to NULL and the variable content_size if initialized to 0 even
** of the parameter content_size isn't. The variable next is
** initialized to NULL. If the allocation fails, the function returns
** NULL. Return value: new link.
*/

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*cur;

	cur = (t_list *)malloc(sizeof(t_list));
	if (!cur)
		return (NULL);
	if (content == NULL)
	{
		cur->content = NULL;
		cur->content_size = 0;
	}
	else
	{
		cur->content = ft_memmove(ft_memalloc(sizeof(void const *)), \
									content, content_size);
		cur->content_size = content_size;
	}
	cur->next = NULL;
	return (cur);
}
