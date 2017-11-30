/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:59:19 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/30 18:14:35 by nschwarz         ###   ########.fr       */
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

int		resolve(char **argv, size_t size);
int		ft_check_map(char *tetri);
char	**parse(char **argv);
char	*ft_read_map(char **argv);
char	**convert(int *ret, int len);
int		ft_parse(int *parsedmap);
int		ft_nbtetri(char **map);
int		*ft_preparse(char *map);
#endif
