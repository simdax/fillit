/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:27:17 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/14 14:34:52 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*data;

	if ((data = (t_list *)malloc(sizeof(*data))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		data->content = NULL;
		data->content_size = 0;
	}
	else
	{
		if ((data->content = malloc(content_size)) == NULL)
		{
			free(data);
			return (NULL);
		}
		ft_memcpy(data->content, content, content_size);
		data->content_size = content_size;
	}
	data->next = NULL;
	return (data);
}
