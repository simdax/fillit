/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:35:57 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/10 13:26:50 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	if (len == 0)
		return (b);
	a = (unsigned char *)b;
	while (len--)
	{
		*a = (unsigned char)c;
		a++;
	}
	return (b);
}
