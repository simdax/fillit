/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:59:19 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/27 19:41:51 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 64
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_read_map(int fd);
char	**convert(char *map);
int		ft_parse(int *parsedmap);
int		ft_nbtetri(char **map);
int		*ft_preparse(char *map);
#endif
