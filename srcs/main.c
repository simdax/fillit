/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/27 19:42:35 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		*ft_caller(char **secmap, int cur)
{
	int		*ret;
	char	*map1d;
	int		*rret;

	map1d = ft_strjoin(secmap[0], secmap[1]);
	map1d = ft_strjoin(map1d, secmap[2]);
	map1d = ft_strjoin(map1d, secmap[3]);
	rret = (int*)malloc(sizeof(int) * (ft_nbtetri(secmap) + 1));
	ret = ft_preparse(map1d);
	rret[cur] = ft_parse(ret);
	return (rret);
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
	while (secmap[i])
	{
		ft_caller(secmap + i, cur);
		i += 4;
		cur++;
	}
	close(fd);
}
