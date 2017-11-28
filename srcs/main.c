/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/28 14:05:39 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include	<stdio.h>

int		ft_caller(char **secmap)
{
	char	*map1d;

	map1d = ft_strjoin(secmap[0], secmap[1]);
	map1d = ft_strjoin(map1d, secmap[2]);
	map1d = ft_strjoin(map1d, secmap[3]);
	return (ft_parse(ft_preparse(map1d)));
}

void	print(int *ret)
{
	while (*ret)
	{
		ft_putnbr(*ret);
		ft_putchar(' ');
		ret++;
	}
}
int		main(int argc, char **argv)
{
	int		fd;
	char	*map;
	char	**secmap;
	int		i;
	int		cur;
	
	cur = 0;
	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(*++argv, O_RDONLY);
	map = ft_read_map(fd);
	secmap = ft_strsplit(map, '\n');
	int	*ret = (int*)malloc(sizeof(int) * (ft_nbtetri(secmap) + 1));
	while (secmap[i])
	{
		ret[cur] = ft_caller(secmap + i);
		i += 4;
		cur++;		
	}
	ret[cur] = 0;
	close(fd);
	print(ret);
	return (0);
}
