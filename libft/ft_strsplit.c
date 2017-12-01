/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:59:50 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/15 11:43:48 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		master(char *str, char c)
{
	int		retourne;
	int		i;

	retourne = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != c)
		{
			if (str[i] != '\0')
				i++;
			else
				break ;
		}
		while (str[i] == c)
			i++;
		retourne++;
	}
	return (retourne);
}

static char		*challenger(char *str, int *index, char c)
{
	int		i;
	int		a;
	int		b;
	char	*retourne;

	a = *index;
	i = a;
	while (str[i] != c)
	{
		if (str[i] != '\0')
			i++;
		else
			break ;
	}
	b = i;
	while (str[i] == c)
		i++;
	*index = i;
	i = -1;
	retourne = (char*)malloc(b - a + 1);
	while (++i < b - a)
		retourne[i] = str[a + i];
	retourne[i] = '\0';
	return (retourne);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**retourne;
	int		i;
	int		index;
	int		a;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	a = master(str, c);
	if ((retourne = (char**)malloc(sizeof(char*) * (a + 1))) == 0)
		return (0);
	i = 0;
	index = 0;
	while (str[0] == c)
		str++;
	while (str[i] != '\0')
		retourne[index++] = challenger(str, &i, c);
	retourne[index] = 0;
	return (retourne);
}
