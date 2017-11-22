/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:36:42 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/22 11:40:18 by abouvero         ###   ########.fr       */
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

t_list  *is_file_valid(char *file);
char  *block_parser(char *b);
void  error(void);
int		ft_placeblock(char *block, char **grid, int cline, int crow, char c);

#endif
