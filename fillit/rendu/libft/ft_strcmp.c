/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:45:43 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/09 18:57:36 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	len = (len1 <= len2) ? len1 : len2;
	i = ft_memcmp(s1, s2, len);
	return (i);
}
