/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/23 17:47:27 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int argc, char**argc)
{
	int		fd;
	char	*map;
	char	**secmap;
	int		*ret;

	if (argc != 1)
	{
		ft_putstr("usage: ./fillit source_file");
		return (0);
	}
	fd = open(*argv, O_RDONLY);
	map = ft_read_map(fd);
	secmap = convert(map);
	ret = ft_parse(secmap);
}
