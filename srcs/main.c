/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:24:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/23 18:23:53 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int argc, char**argv)
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
	fd = open(*argv, O_RDONLY);
	map = ft_read_map(fd);
	secmap = convert(map);
	ret = ft_parse(secmap);
}
