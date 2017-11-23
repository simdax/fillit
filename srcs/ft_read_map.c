/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 20:05:56 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/23 13:06:16 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_map(int fd)
{
	int					ret;
	char				*final;
	char				buf[64];
	unsigned int		i;

	if (fd == -1)
		return (0);
	i = 0;
	final = (char*)malloc(sizeof(char) * 10000);
	while ((ret = read(fd, buf, 64)))
		ft_strncat(final, buf, ret);
	final[i] = '\0';
	i = 0;
	while (final[i++] != '\n')
		;
	ops[2] = final[i - 2];
	ops[1] = final[i - 3];
	ops[0] = final[i - 4];
	return (final + i);
}

int		*ft_parse(char *map)
{
	int		*ret;
}

void	ft_error(char **argv, char *ret)
{
	while (*argv)
	{
		fd = open(*argv, O_RDONLY);
		if (!(ret = ft_read_map(fd)))
		{
/*			ERROR;
			if (!argv[1])
				break ;
			else
			{
				argv++;
				write(1, "\n", 1);
				continue ;
			}
		}
		if (argv[1])
			write(1, "\n", 1);
		argv++; */
	}
}
