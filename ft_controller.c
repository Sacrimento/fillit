/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:34:02 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/29 13:49:40 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_block_sort	*struct_init(t_list *list)
{
	t_block_sort	*tab;
	t_list			*begin;
	int				i;

	tab = (t_block_sort*)malloc(sizeof(t_block_sort) * (ft_list_size(list) + 1));
	i = 0;
	begin = list;
	while (i < ft_list_size(begin))
	{
		(tab[i]).numero = i;
		(tab[i]).block = ft_strdup(list->content);
		list = list->next;
		(tab[i]).placed = 0;
		i++;
	}
	(tab[i]).numero = 42;
	(tab[i]).placed = 1;
	(tab[i]).block = NULL;
	return (tab);
}

void 	ft_print_struct(t_block_sort *tab)
{
	int		i = 0;
	while ((tab[i]).numero != 42)
	{
		printf("[NUMERO : %d] ", (tab[i]).numero);
		printf("[PLACED : %d] ", (tab[i]).placed);
		printf("[BLOCK : %s]\n", (tab[i]).block);
		i++;
	}
}

void ft_controller(t_list *list)
{
	char			**grid;
	t_block_sort	*maintab;

	maintab = struct_init(list);
	ft_print_struct(maintab);
	ft_print_list(list);
	grid = ft_tabcreator(20);
	combv2(maintab, 0, grid);
	ft_print_split(grid);
}
