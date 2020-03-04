/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:23:04 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/04 21:40:10 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	wipe_piece(t_piece **piece)
{
	wipe_mstr((*piece)->mstr);
	free(*piece);
	*piece = NULL;
}
