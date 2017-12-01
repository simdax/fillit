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

#include "fillit.h"

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
