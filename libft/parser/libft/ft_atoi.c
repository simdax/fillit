/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:44:38 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/14 12:13:59 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	i;
	long	n;
	long	r;

	i = 0;
	n = 0;
	r = 0;
	while ((str[i] == '\n') || (str[i] == '\t')
			|| (str[i] == '\v') || (str[i] == '\f')
			|| (str[i] == ' ') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		r = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - 48;
		i++;
	}
	if (r == 1)
		return (-n);
	return ((int)n);
}
