/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:09:33 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/24 11:26:26 by scornaz          ###   ########.fr       */
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

static int		ft_nbtetri(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
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
