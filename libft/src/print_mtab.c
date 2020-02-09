/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:04:06 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/09 02:20:56 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function prints matrix of integers;
** it can be easily tweaked to print what you want for the task at hand
*/

#define RED		"\x1B[31m"
#define GRN		"\x1B[32m"
#define YEL		"\x1B[33m"
#define BLU		"\x1B[34m"
#define MAG		"\x1B[35m"
#define CYN		"\x1B[36m"
#define WHT		"\x1B[37m"

#define RESET	"\x1B[0m"

#define BG_RED	"\x1B[41m"
#define BG_GRN	"\x1B[42m"
#define BG_YEL	"\x1B[43m"
#define BG_BLU	"\x1B[44m"
#define BG_MAG	"\x1B[45m"
#define BG_CYN	"\x1B[46m"
#define BG_WHT	"\x1B[47m"

#include <stdio.h> // remove later!

#include "libft.h"

void	print_mtab(int **matrix, size_t rows, size_t cols)
{
	size_t		i;
	size_t		j;

	if (matrix)
	{
		i = 0;
		j = 0;
		while (i < rows)
		{
			if (j == cols)
			{
				j = 0;
				i += 1;
				ft_putchar('\n');
				continue ;
			}
			if (ft_isprint(matrix[i][j]))
			{
				if (matrix[i][j] == 'o')
					printf(RED "%c" RESET, (char)(matrix[i][j]));
				if (matrix[i][j] == 'O')
					printf(BLU "%c" RESET, (char)(matrix[i][j]));
				else if (matrix[i][j] == 'X')
					printf(MAG "%c" RESET, (char)(matrix[i][j]));
				else if (matrix[i][j] == 'x')
					printf(BG_MAG "%c" RESET, (char)(matrix[i][j]));
				else if (matrix[i][j] == '.')
					printf(CYN "%c" RESET, (char)(matrix[i][j]));
			}
			else if (matrix[i][j] % 10 == 0)
				printf(YEL "%d" RESET, matrix[i][j] % 10);
			else
				printf(YEL "%d" RESET, matrix[i][j] % 10);
			ft_putchar(' ');
			j++;
		}
	}
	ft_putendl("print_mtab: finished\n");
}
