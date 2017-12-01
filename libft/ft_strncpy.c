/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:17:43 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/14 11:46:59 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	l;

	l = 0;
	while (src[l] != '\0' && l < len)
	{
		dst[l] = src[l];
		l++;
	}
	while (l < len)
	{
		dst[l] = '\0';
		l++;
	}
	return (dst);
}
