/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/12/01 11:44:56 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_nbtetri(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

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
	map1d = ft_strjoin(secmap[0], secmap[1]);
	map2d = ft_strjoin((ft_strjoin(mapcpy[0], tmp)), mapcpy[1]);
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
	res = (char**)malloc(sizeof(char*) * (len + 1));
	while (i < len)
	{
		res[i] = ft_itoa(ret[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

int		ft_check_n(char *map, int nb_tetri)
{
	int		i;
	int		len;
	int		inc;

	len = ft_strlen(map);
	inc = 0;
	i = 0;
	if (len < 20)
		return (0);
	if (len != (20 + (21 * (nb_tetri - 1))))
		return (0);
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
	char	*map;
	char	**secmap;
	int		cur;
	int		nb_tetri;
	int		*ret;

	cur = 0;
	map = ft_read_map(argv);
	secmap = ft_strsplit(map, '\n');
	nb_tetri = ft_nbtetri(secmap) / 4;
	if (!(ft_check_n(map, nb_tetri)))
		return (0);
	ret = (int*)malloc(sizeof(int) * (nb_tetri + 1));
	nb_tetri = 0;
	while (secmap[nb_tetri])
	{
		if (((ret[cur] = ft_caller(secmap + nb_tetri)) == -1))
			return (0);
		nb_tetri += 4;
		cur++;
	}
	return (convert(ret, ft_nbtetri(secmap) / 4));
}
