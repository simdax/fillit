/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:48:50 by scornaz           #+#    #+#             */
/*   Updated: 2017/11/22 18:15:14 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "tetrominos.h"

void	dod(char **coucou)
{
	while (*coucou) {
		printf("%s", *coucou++);	
	}
	printf("\n");
}

int		add(char *tetromino, char *matrice, size_t pos, size_t size)
{
	while (*tetromino)
	{
		if (*tetromino == '#')
		{
			if (matrice[pos] == '.')
				matrice[pos] = '#';
			else
				return (0);
		}
		else if (*tetromino == '\n')
			pos += size - 5;
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

void	resolve(char **list, int len, int size)
{
	(void)list;
	(void)len;

	char *matrice;

	int i = 0;
	while (i < 19)
	{
		matrice = set_matrice(size);
		add(g_tetros[i], matrice, 0, size);
		printf("%s\n", matrice);
		i++;
	}
}


int 	main(int argc, char **argv)
{
	if (argc > 0) {		
		argv++;
		resolve(argv, argc - 2, 4);
	}	 
	return 0;
}
