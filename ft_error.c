/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:34:22 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/30 11:38:04 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	ft_check_map(char *tetri)
{
	int		i;
	int		n;
	int		point;
	int		hash;

	i = 0;
	n = 0;
	point = 0;
	hash = 0;
	while (tetri[i] != '\0' && i < 20)
	{
		if ((i + 1) % 5 == 0 && tetri[i] == '\n')
			n++;
		else if (tetri[i] == '.')
			point++;
		else if (tetri[i] == '#')
			hash++;
		i++;
	}
	return ((tetri[i] == '\n' || tetri[i] == '\0')
			&& (n == 4 && point == 12 && hash == 4) ? 1 : 0);
}
