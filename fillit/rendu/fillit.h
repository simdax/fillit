/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:51:38 by nschwarz          #+#    #+#             */
/*   Updated: 2017/11/30 19:45:16 by nschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

int		add(char **argv, t_board board, int len, int index);
int		clean(char *matrice, int places[4]);
char	**convert(int *ret, int len);
int		ft_caller(char **secmap);
int		ft_check_map(char *tetri);
int		ft_check_n(char *map, int nb_tetri);
int		ft_intcmp(int *a, int *b);
int		ft_nbtetri(char **map);
int		ft_parse(int *parsedmap);
int		*ft_preparse(char *map);
char	*ft_read_map(char **argv);
void	fuck_norminette(unsigned int *row, size_t *pos, size_t size);
void	fuck_norminette2(unsigned int *row, unsigned int *col,
		size_t pos, size_t size);
void	fuck_norminette3(int puts[4], size_t i, size_t pos, unsigned int col);
char	**parse(char **argv);
int		place(char *tetromino, t_board board, size_t pos, size_t index);
void	print(char *matrice, size_t size);
void	remove_piece(char *matrice, int index);
int		resolve(char **argv, size_t size);
char	*set_matrice(int size);

#endif
