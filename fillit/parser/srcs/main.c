/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/30 15:20:21 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_caller(char **secmap)
{
	char	*map1d;
	char	*map2d;
	char	*tmp;
	char	**mapcpy;

	tmp = (char*)malloc(sizeof(char) * 2);
	tmp[0] = '\n';
	tmp[1] = '\0';
	mapcpy = (char **)malloc(sizeof(char *) * 4);
	mapcpy[0] = secmap[0];
	mapcpy[1] = secmap[1];
	mapcpy[2] = secmap[2];
	mapcpy[3] = secmap[3];
	mapcpy[0] = ft_strjoin(mapcpy[0], tmp);
	map1d = ft_strjoin(secmap[0], secmap[1]);
	map2d = ft_strjoin(mapcpy[0], mapcpy[1]);
	map2d = ft_strjoin(map2d, tmp);
	map1d = ft_strjoin(map1d, secmap[2]);
	map2d = ft_strjoin(map2d, mapcpy[2]);
	map2d = ft_strjoin(map2d, tmp);
	map1d = ft_strjoin(map1d, secmap[3]);
	map2d = ft_strjoin(map2d, mapcpy[3]);
	map2d = ft_strjoin(map2d, tmp);
	if (ft_check_map(map2d) == 0)
		return (-1);
	return (ft_parse(ft_preparse(map1d)));
}

char	**convert(int *ret, int len)
{
	char	**res;
	int		i;

	i = 0;
	res = (char**)malloc(sizeof(char*) * len + 1);
	while (i < len)
	{
		res[i] = ft_itoa(ret[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

int		ft_check_n(char *map)
{
	int		i;
	int		len;
	int		inc;

	len = ft_strlen(map);
	inc = 0;
	i = 0;
	while (map[i] && i < len - 21)
	{
		i += 20 + inc;
		if (map[i] != '\n')
			return (0);
		inc = 1;
	}
	return (1);
}

char	**parse(char **argv)
{
	int		fd;
	char	*map;
	char	**secmap;
	int		i;
	int		cur;
	int		nb_tetri;
	int		*ret;

	cur = 0;
	i = 0;
	fd = open(*++argv, O_RDONLY);
	map = ft_read_map(fd);
	secmap = ft_strsplit(map, '\n');
	nb_tetri = ft_nbtetri(secmap) / 4;
	if (!(ft_check_n(map)))
		return (0);
	ret = (int*)malloc(sizeof(int) * (nb_tetri + 1));
	while (secmap[i])
	{
		if (((ret[cur] = ft_caller(secmap + i)) == -1))
				return (0);
		i += 4;
		cur++;
	}
	close(fd);
	return (convert(ret, nb_tetri));
}
