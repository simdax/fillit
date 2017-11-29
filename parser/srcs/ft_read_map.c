/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:09:33 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/29 10:45:01 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "tetrominos.h"
#include "tetrominos2.h"

char	*ft_read_map(int fd)
{
	int		ret;
	char	*final;
	char	buf[256];

	if (fd == -1)
		return (0);
	ret = 0;
	ret = read(fd, buf, 256);
	buf[ret] = '\0';
	if (!(final = ft_strnew(ret)))
		return (NULL);
	ft_strcpy(final, buf);
	return (final);
}

int		ft_intcmp(int *a, int *b)
{
	int	i;

	i = 0;
	while (i < 4 && a[i] - b[i] == 0)
		i++;
	if (i == 4)
		return (1);
	else
		return (0);
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
			a++;
		}
		i++;
		if (tmp != 5000)
			tmp++;
	}
	return (ret);
}

int		ft_parse(int *parsedmap)
{
	int		i;

	i = 0;
	while (g_tetros2[i])
	{
		if (ft_intcmp(parsedmap, g_tetros2[i]))
			return (i);
		i++;
	}
	return (0);
}
