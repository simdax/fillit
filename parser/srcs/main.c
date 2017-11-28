/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/28 15:41:10 by scornaz          ###   ########.fr       */
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

char	**convert(int *ret, int len)
{
	char **res;

	res = (char**)malloc(sizeof(char*) * 26);
	while (len--)
	{
		*res = ft_itoa(*ret);
		ret++;
		res++;
	}
	return (res);
}

char		**parse(int argc, char **argv)
{
	int		fd;
	char	*map;
	char	**secmap;
	int		i;
	int		cur;
	int		nb_tetri;
			
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
	nb_tetri = ft_nbtetri(secmap) / 4;
	int	*ret = (int*)malloc(sizeof(int) * (nb_tetri + 1));
	while (secmap[i])
	{
		ret[cur] = ft_caller(secmap + i);
		i += 4;
		cur++;		
	}
	ret[cur] = 0;
	close(fd);
	return(convert(ret, nb_tetri));
}
