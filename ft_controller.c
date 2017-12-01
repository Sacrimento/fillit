/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:34:02 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/01 15:27:18 by mfonteni         ###   ########.fr       */
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
		(tab[i]).block = ft_strdup(list->content);
		list = list->next;
		(tab[i]).placed = 0;
		i++;
	}
	(tab[i]).placed = 1;
	(tab[i]).block = NULL;
	return (tab);
}

static void		ft_clear_placement(t_block_sort *tab)
{
	int count;

	count = 0;
	while (count <= block_tab_size(tab))
		(tab[count++]).placed = 0;

}
/*
static void 	ft_print_struct(t_block_sort *tab)
{
	int		i = 0;
	while ((tab[i]).block)
	{
		printf("[PLACED : %d] ", (tab[i]).placed);
		printf("[BLOCK : %s]\n", (tab[i]).block);
		i++;
	}
		printf("[PLACED : %d] ", (tab[i]).placed);
		printf("[BLOCK : %s]\n", (tab[i]).block);

}*/

void ft_controller(t_list *list)
{
	char			**grid;
	t_block_sort	*maintab;
	int				limit;

	limit = TAB_MAX - 2;
	grid = ft_tabcreator(30);
	maintab = struct_init(list);
///////////////=======================debug==========================
//	ft_print_struct(maintab);
//	ft_print_list(list);


	while (limit > 1 && ft_combination(maintab, 0, grid))
	{
		limit = ft_gridsize(grid);
		ft_clear_placement(maintab);
		ft_memdel((void**)grid);
		grid = ft_tabcreator(--limit);
	}
	ft_clear_placement(maintab);
	ft_memdel((void**)grid);
	grid = ft_tabcreator(limit+1);
	ft_combination(maintab, 0, grid);
}
