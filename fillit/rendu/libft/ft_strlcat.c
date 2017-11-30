/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:33:34 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/13 15:14:07 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ret;
	char	*s;
	size_t	len;

	ret = (char *)ft_memchr(dst, '\0', size);
	if (ret == NULL)
		return (size + ft_strlen(src));
	s = (char *)src;
	len = (size_t)(ret - dst) + ft_strlen(s);
	while ((size_t)(ret - dst) < size - 1 && *s != '\0')
	{
		*ret = *s;
		ret++;
		s++;
	}
	*ret = '\0';
	return (len);
}
