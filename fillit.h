/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:36:42 by abouvero          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/24 18:50:51 by mfonteni         ###   ########.fr       */
=======
/*   Updated: 2017/11/24 16:22:57 by abouvero         ###   ########.fr       */
>>>>>>> d1065f20053e820d4fdcf6c616b1d4227d6d6150
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# include <stdio.h>

# define BUFF_SIZE 4096
# define ALPHAPOS 65

t_list  *is_file_valid(char *file);
char    *block_parser(char *b);
void    error(void);
int     ft_placeblock(char *block, char **grid, int cline, int crow);
int     ft_alphablock(char **grid, char c);
void	ft_eraseblock(char **frid, char c);
int		*nextpos(char **grid, int max);

#endif
