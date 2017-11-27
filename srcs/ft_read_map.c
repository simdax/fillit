/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:09:33 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/27 12:20:38 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "tetrominos.h"

char	*ft_read_map(int fd)
{
	int		ret;
	char	*final;
	char	buf[BUF_SIZE + 1];

	if (fd == -1)
		return (0);
	ret = 0;
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(final = ft_strnew(ret)))
		return (NULL);
	ft_strcpy(final, buf);
	return (final);
}

int		ft_nbtetri(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int		*ft_preparse(char *map)
{
	int				*ret;
	int				i;
	int				tmp;
	int				b;
	int				a;

	i = 0;
	a = 0;
	b = 0;
	tmp = 5000;
	ret = (int*)malloc(sizeof(int) * 4);
	while (map[i])
	{
		if (map[i] == '#')
		{
			if (tmp == 5000)
			{
				ret[a] = 0;
				tmp = 0;
				b = i;
			}
			if (tmp != 5000)
				ret[a] = i - b;
			tmp++;
	//		i++;
			a++;
		}
		i++;
		if (tmp != 5000)
			tmp++;
	}
	printf ("%d, %d, %d, %d", ret[0], ret[1], ret[2], ret[3]);
	return (ret);
}

int		*ft_parse(char **map)
{
	int		*ret;
	int		i;
	int		cur;

	cur = 0;
	ret = (int*)malloc(sizeof(int*) * (ft_nbtetri(map) + 1));
	while (map[cur])
	{
		while (g_tetros[i])
		{
			if (ft_strcmp(map[cur], g_tetros[i]) == 1)
			{
				ret[cur] = i;
				break ;
			}
			i++;
		}
		i = 0;
		cur++;
	}
	return (ret);
}
