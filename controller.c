/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:34:02 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 15:02:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_block_sort	*struct_init(t_list *list)
{
	t_block_sort	*tab;
	t_list			*begin;
	int				i;

	tab = (t_block_sort*)malloc(
			sizeof(t_block_sort) * (ft_list_size(list) + 1));
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

static void			ft_clear_placement(t_block_sort *tab)
{
	int count;

	count = 0;
	while (count <= block_tab_size(tab))
		(tab[count++]).placed = 0;
}

static char			**reset_grid(t_block_sort *maintab, char **grid, int limit)
{
	int count;

	count = 0;
	ft_clear_placement(maintab);
	while (grid[count])
		ft_memdel((void**)&grid[count]);
	ft_memdel((void**)grid);
	grid = tabcreator(limit);
	return (grid);
}

void				controller(t_list *list)
{
	char			**grid;
	t_block_sort	*maintab;
	int				limit;

	limit = TAB_MAX;
	grid = tabcreator(30);
	maintab = struct_init(list);
	combination(maintab, 0, grid);
	limit = gridsize(grid) + 2;
	grid = reset_grid(maintab, grid, limit);
	while (limit > 0 && combination(maintab, 0, grid))
		grid = reset_grid(maintab, grid, --limit);
	grid = reset_grid(maintab, grid, ++limit);
	combination(maintab, 0, grid);
	print_grid(grid);
}
