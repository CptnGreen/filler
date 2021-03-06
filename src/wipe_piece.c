/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:31:57 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/03 05:04:41 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	wipe_piece(t_piece *piece)
{
	if (piece)
	{
		wipe_mstr(piece->mstr);
		piece = NULL;
	}
}
