/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:31:05 by scornaz           #+#    #+#             */
/*   Updated: 2017/11/30 18:32:04 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit2.h"

int		clean(char *matrice, int places[3])
{
	while (*places != -1)
		matrice[*places++] = '.';
	return (0);
}

char		*set_matrice(int size)
{
	char	*matrice;

	matrice = (char*)malloc(sizeof(char) * (size * size + 1));
	memset(matrice, '.', size * size);
	matrice[size * size] = 0;
	return (matrice);
}

void		fuck_norminette(unsigned int *row, size_t *pos, size_t size)
{
	*row += 1;
	*pos += size - 5;
}

void		fuck_norminette2(unsigned int *row, unsigned int *col,
							size_t pos, size_t size)
{
	*col = pos % size;
	*row = pos / size;
}

void		fuck_norminette3(int puts[4], size_t i,
					size_t pos, unsigned int col)
{
	puts[i++] = pos;
	col++;
}
