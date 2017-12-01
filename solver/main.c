/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:48:50 by scornaz           #+#    #+#             */
/*   Updated: 2017/11/29 11:00:40 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit2.h"
#include "libft.h"
#include "tetrominos.h"

void	print(char *matrice, size_t size)
{
	size_t	i;

	i = 0;
	while (*matrice)
	{
		if (i && !(i % size))
			ft_putchar('\n');
		ft_putchar(*matrice++);
		i++;
	}
	ft_putstr("\n");
}

void	clean(char *matrice, int places[4])
{
	while (*places != -1)
		matrice[*places++] = '.';
}

char	*set_matrice(int size)
{
	char	*matrice;

	matrice = (char*)malloc(sizeof(char) * (size * size + 1));
	memset(matrice, '.', size * size);
	matrice[size * size] = 0;
	return (matrice);
}

int		place(char *tetromino, char *matrice, size_t pos, size_t size, size_t index)
{
	unsigned int	row;
	unsigned int	col;
	int				puts[4];
	size_t			i;

	i = 0;
	ft_memset(puts, -1, sizeof(int) * 4);
	col = pos % size;
	row = pos / size;
	while (*tetromino)
	{
		if (*tetromino == '#')
		{
			if (matrice[pos] != '.' ||
				pos / size > row)
			{
				clean(matrice, puts);
				return (0);
			}
			puts[i++] = pos;
			col++;
			matrice[pos] = 'A' + index;
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

void	remove_piece(char *matrice, int index)
{
	while (*matrice)
	{
		if (*matrice == 'A' + index)
			*matrice = '.';
		matrice++;
	}
}

int		add(char **argv, char *matrice, size_t size, int len, int index)
{
	unsigned int	j;

	j = 0;
	if (index == len)
		return (1);
	while (j < size * size)
	{
		if ((place(g_tetros[atoi(argv[index])], matrice, j, size, index)))
		{
			if (add(argv, matrice, size, len, index + 1))
				return (1);
			else
				remove_piece(matrice, index);
		}
		j++;
	}
	return (0);
}

int		resolve(char **argv, size_t size)
{
	char		*matrice;
	size_t		t;
	int			res;

	res = 0;
	t = 0;
	while (argv[t])
		t++;
	matrice = set_matrice(size);
	res = add(argv, matrice, size, t, 0);
	if (!res)
		resolve(argv, size + 1);
	else
		print(matrice, size);
	return (0);
}
