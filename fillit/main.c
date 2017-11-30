/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:53:45 by scornaz           #+#    #+#             */
/*   Updated: 2017/11/29 14:56:43 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include "libft.h"

int		resolve(char **argv, size_t size);
char	**parse(int argc, char **argv);

int main(int argc, char **argv)
{
	char	**parsed;

	if (!(parsed = parse(argc, argv)))
		ft_putstr("error.");
	else
		resolve(parsed, 3);
	free(parsed);
}
