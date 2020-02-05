/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 03:08:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 03:26:44 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NODE_H
# define T_NODE_H

/*
** u - up, r - right, d - down, l - left,
** p - previously covered, s - superior,
** l_sp - left spacer, r_sp - right spacer,
** z - zero node
*/

typedef sctruct		s_node{
	struct s_node	*u;
	struct s_node	*r;
	struct s_node	*d;
	struct s_node	*l;
	struct s_node	*p;
	struct s_node	*s;
	struct s_node	*l_sp;
	struct s_node	*r_sp;
	struct s_node	*z;
	int				n;
	int				x;
	int				y;
	char			role;
	char			c;
}					t_node;

#endif
