/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:08:42 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/15 11:26:14 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static size_t	length(int n)
{
	size_t i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char				*str;
	size_t				len;
	unsigned int		r;

	len = length(n);
	r = n;
	if (n < 0)
	{
		r = -n;
		len++;
	}
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[--len] = r % 10 + '0';
	while (r)
	{
		r /= 10;
		str[--len] = r % 10 + '0';
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
