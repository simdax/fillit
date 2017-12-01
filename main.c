/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:53:45 by scornaz           #+#    #+#             */
/*   Updated: 2017/11/30 12:25:04 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include "libft.h"

int		resolve(char **argv, size_t size);
char	**parse(char **argv);

int main(int argc, char **argv)
{
	char	**parsed;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!(parsed = parse(argv)))
		ft_putstr_fd("error\n", 2);
	else
		resolve(parsed, 3);
	free(parsed);
}
