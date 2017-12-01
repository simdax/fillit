/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:12:46 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/14 13:30:19 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	int		l;
	size_t	i;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (*n == '\0')
		return (h);
	l = ft_strlen(n);
	while (h[i] != '\0' && (i + l) <= len)
	{
		if (h[i] == *n && ft_memcmp(h + i, n, l) == 0)
			return (h + i);
		i++;
	}
	return (NULL);
}
