/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:09:33 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/30 19:51:04 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "tetrominos2.h"

char	*ft_read_map(char **argv)
{
	int		ret;
	char	*final;
	char	buf[256];
	int		fd;

	if ((fd = open(*++argv, O_RDONLY)) == -1)
		return (0);
	ret = 0;
	ret = read(fd, buf, 256);
	buf[ret] = '\0';
	if (!(final = ft_strnew(ret)))
		return (NULL);
	ft_strcpy(final, buf);
	close(fd);
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

void	retardfunctionexe2000(int *a, int *b, int *i)	
{
	*a = 0;
	*b = 0;
	*i = 0;
}

int		*ft_preparse(char *map)
{
	int				*ret;
	int				i;
	int				b;
	int				a;

	retardfunctionexe2000(&a, &b, &i);
	ret = (int*)malloc(sizeof(int) * 4);
	while (map[i])
	{
		if (map[i] == '#')
		{
			if (!a)
			{
				ret[a] = 0;
				b = i;
			}
			if (a)
				ret[a] = i - b;
			a++;
		}
		i++;
	}
	return (ret);
}

int		ft_parse(int *parsedmap)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (ft_intcmp(parsedmap, g_tetros2[i]))
			return (i);
		i++;
	}
	return (-1);
}
