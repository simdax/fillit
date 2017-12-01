/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:45:10 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/13 16:08:55 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	size_t	len;

	h = (char *)haystack;
	n = (char *)needle;
	if (*n == '\0')
		return (h);
	len = ft_strlen(n);
	while (*h != '\0')
	{
		if (*h == *n && ft_memcmp(h, n, len) == 0)
			return (h);
		h++;
	}
	return (NULL);
}
