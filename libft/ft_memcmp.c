/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:57:44 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/10 12:02:15 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *string1;
	unsigned const char *string2;

	if (s1 == s2 || n == 0)
		return (0);
	string1 = (unsigned const char *)s1;
	string2 = (unsigned const char *)s2;
	while (n)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		if (n)
		{
			string1++;
			string2++;
		}
		n--;
	}
	return (0);
}
