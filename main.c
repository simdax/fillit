/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:48:50 by scornaz           #+#    #+#             */
/*   Updated: 2017/11/22 19:20:02 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "tetrominos.h"

void	print(char *matrice, size_t size)
{
	size_t	i;

	i = 0;
	while (*matrice) {
		if (i && !(i % size))
			printf("\n");
		ft_putchar(*matrice++);
		i++;
	}
	ft_putstr("\n\n");
}

int		add(char *tetromino, char *matrice, size_t pos, size_t size)
{
	unsigned int	row;

	row = pos / size;
	while (*tetromino)
	{
		if (*tetromino == '#')
		{
			if (pos > size * size || pos / size > row)
				return (0);
			else if (matrice[pos] == '.')
				matrice[pos] = '#';
		}
		else if (*tetromino == '\n')
		{
			row++;
			pos += size - 5;
		}
		tetromino++;
		pos++;
	}
	return (1);
}

char	*set_matrice(int size)
{
	char	*matrice;

	matrice = (char*)malloc(sizeof(char) * (size * size + 1));
	memset(matrice, '.', size*size);
	matrice[size * size] = 0;
	return (matrice);
}

int		resolve(int size)
{
	char *matrice;
	int i = 0;
	while (i < 19)
	{
		matrice = set_matrice(size);
		printf("%d", add(g_tetros[i], matrice, 5, size));
		print(matrice, size);
		i++;
	}
	return (0);
}


int 	main(int argc, char **argv)
{
	if (argc > 0) {		
		argv++;
		resolve(4);
	}	 
	return 0;
}
