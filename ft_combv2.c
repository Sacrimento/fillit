/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:34:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/29 14:00:53 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* ft_combv2 a combinasion generator with recursive backtracking
 * ///////////////=================================================
 * maintab is a struct array with the blocks in alphabetic order
 * curentab was a fresh tab large as maintab where we stored the current combinasion
 * trough the recursion, quite useless : I try to do the job without
 * it but it use to help me visualise the current action
 * ///////////////=================================================
 */

/* trying a first time, and give the new limit as reference for another loop,
 * if the program fails with the new limits it means we got the perfect solution
 */

static int			is_blocks_left(t_block_sort *tab)
{
	int		i;

	i = 0;
	while ((tab[i]).numero != 42)
	{
		if (!((tab[i]).placed))
			return (1);
		i++;
	}
	return (0);
}

static int			tab_size(t_block_sort *tab)
{
	int		i;

	i = 0;
	while ((tab[i]).numero != 42)
		i++;
	return (i - 1);
}


static int			already_set(t_block_sort block)
{
	if (block.placed)
		return (1);
	return (0);
}

static t_block_sort	mark_as_set(t_block_sort block)
{
	block.placed = 1;
	return (block);
}

static t_block_sort	mark_as_notset(t_block_sort block)
{
	block.placed = 0;
	return (block);
}

int combv2(t_block_sort *maintab, int start, char **grid)
{
	if (!is_blocks_left(maintab))
		return (1);
	if (start > tab_size(maintab) || (maintab[start]).numero == 42)
		return (0);
	while (start < tab_size(maintab) && already_set(maintab[start]))
	{
		printf("already_set, move trought the array case : %d\n", start);
		start++;
	}
	if	(!ft_placenext((maintab[start]).block, grid, 19, (maintab[start]).numero + 65))
	{
		printf("placement failed for %s, retry with another block\n", (maintab[start]).block);
		return (combv2(maintab, start + 1, grid));
	}
	else
	{
		printf("success of placement : %s\n", (maintab[start]).block);
		maintab[start] = mark_as_set(maintab[start]);
		ft_print_split(grid);
	}
	if (combv2(maintab, 0, grid))
	{
		printf("success of next recursion\n");
		return (1);
	}
	else
	{
		maintab[start] = mark_as_notset(maintab[start]);
		ft_eraseblock(grid, (maintab[start]).numero + 65);
		printf("retry after fail\n");
		return (combv2(maintab, start + 1, grid));
	}
	printf("global fail");
	return (0);
}
