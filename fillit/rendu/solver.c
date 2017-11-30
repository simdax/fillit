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
#include "struct.h"

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

int		place(char *tetromino, t_board board, size_t pos, size_t index)
{
	unsigned int	row;
	unsigned int	col;
	int				puts[4];
	size_t			i;

	fuck_norminette2(&col, &row, pos, board.size);
	i = 0;
	while (*tetromino)
	{
		if (*tetromino == '#')
		{
			if (board.matrice[pos] != '.' || pos / board.size > row)
			{
				clean(board.matrice, puts);
				return (0);
			}
			fuck_norminette3(puts, i, pos, col);
			board.matrice[pos] = 'A' + index;
		}
		else if (*tetromino == '\n')
			fuck_norminette(&row, &pos, board.size);
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

int		add(char **argv, t_board board, int len, int index)
{
	unsigned int	j;
	unsigned int	sqr;

	sqr = board.size * board.size;
	j = 0;
	if (index == len)
		return (1);
	while (j < sqr)
	{
		if ((place(g_tetros[ft_atoi(argv[index])], board, j, index)))
		{
			if (add(argv, board, len, index + 1))
				return (1);
			else
				remove_piece(board.matrice, index);
		}
		j++;
	}
	return (0);
}

int		resolve(char **argv, size_t size)
{
	t_board		board;
	size_t		t;
	int			res;

	res = 0;
	t = 0;
	while (argv[t])
		t++;
	board.matrice = set_matrice(size);
	board.size = size;
	res = add(argv, board, t, 0);
	if (!res)
		resolve(argv, size + 1);
	else
		print(board.matrice, size);
	return (0);
}
