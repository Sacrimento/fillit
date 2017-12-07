/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:36:42 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/07 19:06:02 by mfonteni         ###   ########.fr       */
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
# define TAB_MAX 13

typedef struct	s_block_sort
{
	int		placed;
	char	*block;
}				t_block_sort;

t_list			*is_file_valid(char *file);
char			*block_parser(char *b);
void			error(void);
int				placeblock(char *block, char **grid, int line, int row);
int				alphablock(char **grid, char letter);
void			eraseblock(char **grid, char letter);
char			**tabcreator(int size);
int				placenext(char *block, char **grid, char letter, int decal);
void			controller(t_list *list);
void			print_grid(char **tab);
int				combination(t_block_sort *maintab, int start,
							char **grid, int decal);
int				is_blocks_left(t_block_sort *tab);
int				block_tab_size(t_block_sort *block);
int				already_set(t_block_sort block);
t_block_sort	mark_as_set(t_block_sort block);
t_block_sort	mark_as_notset(t_block_sort block);
int				search_block(char *block, char **grid, int line, int row);
int				chk_limit(char **grid);
int				gridsize(char **grid);

#endif
