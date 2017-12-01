/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:53:45 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/01 12:25:09 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	stupid(size_t *i, size_t *pos, size_t *size, unsigned int *row)
{
	*i = 0;
	*row = *pos / *size;
}

int		main(int argc, char **argv)
{
	char	**parsed;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!(parsed = parse(argv)))
		ft_putstr("error\n");
	else
		resolve(parsed, 3);
}
