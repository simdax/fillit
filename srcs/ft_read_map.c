/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:09:33 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/24 17:48:41 by nschwarz         ###   ########.fr       */
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

int		ft_preparse(char **map)
{
	unsigned int	col;
	unsigned int	row;
	int				*ret;
	int				i;
	int				tmp;
	int				a;

	col = 4;
	row = 4;
	i = 0;
	a = 0;
	tmp = 5000;
	ret = (int*)malloc(sizeof(int*) * 4);
	while (map[i])
	{
		if (map[i] == '#')
		{
			if (tmp == 5000)
			{
				ret[a] == 0;
				tmp = 0;
			}
			else
				ret[a] == tmp;
			tmp++;
			i++;
			a++;
		}
		i++;
		if (tmp != 5000)
			tmp++;
	}
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
