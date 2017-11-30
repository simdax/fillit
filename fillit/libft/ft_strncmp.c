/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:16:07 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/13 16:18:18 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	len = (len1 <= len2) ? len1 : len2;
	len = (len <= n) ? len : n;
	i = ft_memcmp(s1, s2, len);
	return (i);
}
