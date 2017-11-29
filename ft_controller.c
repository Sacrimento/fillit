/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:34:02 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/29 20:06:52 by mfonteni         ###   ########.fr       */
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

static void 	ft_print_struct(t_block_sort *tab)
{
	int		i = 0;
	while ((tab[i]).block)
	{
		printf("[PLACED : %d] ", (tab[i]).placed);
		printf("[BLOCK : %s]\n", (tab[i]).block);
		i++;
	}
}

void ft_controller(t_list *list)
{
	char			**grid;
	t_block_sort	*maintab;
	int				limit;
	int				result;


	limit = TAB_SIZE;
	result = 0;

	grid = ft_tabcreator(TAB_SIZE);
	maintab = struct_init(list);
	ft_print_struct(maintab);
	ft_print_list(list);

	while (ft_combination(maintab, 0, grid, limit))
	{
		limit = (ft_gridsize(grid) < limit ? ft_gridsize(grid) : limit);
		ft_memdel((void**)grid);
		grid = ft_tabcreator(TAB_SIZE);
		limit--;
	}
	ft_combination(maintab, 0, grid, limit);
	ft_print_split(grid, limit);
}
