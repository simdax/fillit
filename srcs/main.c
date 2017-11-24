/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/24 14:18:40 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*map;
	char	**secmap;
	int		*ret;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		return (0);
	}
	fd = open(*++argv, O_RDONLY);
	map = ft_read_map(fd);
	secmap = ft_strsplit(map, '\n');
	ret = (int*)malloc(sizeof(int*) * (ft_nbtetri(secmap) + 1));
	ret = ft_parse(secmap);
	close(fd);
}
